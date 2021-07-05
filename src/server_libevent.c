/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    server_libevent.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 16:03
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 16:03
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/thread.h>

#include "server_libevent.h"
#include "server_com.h"

#include "hy_utils/hy_log.h"
#define ALONE_DEBUG 1

typedef struct {
    struct event_base   *base;
    struct bufferevent  *bev;
    pthread_t           id;

    ServerCb_t          cb;
} server_libevent_context_t;

static void _libevent_destroy(server_libevent_context_t *context);

int server_libevent_write(void *handle, void *data, size_t len)
{
    server_libevent_context_t *context = handle;

    return bufferevent_write(context->bev, data, len);
}

static void _socket_read_cb(struct bufferevent *bev, void *arg)
{
    server_libevent_context_t *context = arg;

    char buf[1024] = {0}; 
    size_t ret = bufferevent_read(bev, buf, sizeof(buf));

    if (context->cb.data_cb) {
        context->cb.data_cb(buf, ret, context->cb.args);
    }
}

static void _socket_write_cb(struct bufferevent *bev, void *arg)
{
}

static void _socket_event_cb(struct bufferevent *bev, short events, void *arg)
{
    server_libevent_context_t *context = arg;

    if (events & BEV_EVENT_EOF) {
        LOGE("connection closed \n");
    } else if(events & BEV_EVENT_ERROR) {
        LOGE("some other error \n");
    } else if(events & BEV_EVENT_CONNECTED) {
        LOGI("connect to the server \n");

        if (context && context->cb.state_cb) {
            context->cb.state_cb(SERVER_STATE_CONNECTED, context->cb.args);
        }

        return;
    }

    bufferevent_free(context->bev);
    context->bev = NULL;
}

static void *_event_base_dispatch_loop(void *args)
{
    server_libevent_context_t *context = args;

    event_base_dispatch(context->base);

    if (context && context->cb.state_cb) {
        context->cb.state_cb(SERVER_STATE_DISCONNECT, context->cb.args);
    }

    return NULL;
}

static int _libevent_create(server_libevent_context_t *context,
        ServerConfig_t *server_config)
{
    do {
#ifdef _WIN32
        evthread_use_windows_threads();
#endif
#ifdef __GNUC__
        evthread_use_pthreads();
#endif
        context->base = event_base_new();
        if (!context->base) {
            LOGE("event_base_new faild \n");
            break;
        }

        context->bev = bufferevent_socket_new(context->base,
                -1, BEV_OPT_CLOSE_ON_FREE);
        if (!context->bev) {
            LOGE("bufferevent_socket_new faild \n");
            break;
        }

        struct sockaddr_in serv;
        memset(&serv, 0, sizeof(serv));
        serv.sin_family = AF_INET;
        serv.sin_port = htons(server_config->port);
        evutil_inet_pton(AF_INET, server_config->ip, &serv.sin_addr.s_addr);

        if (0 != bufferevent_socket_connect(context->bev,
                    (struct sockaddr*)&serv, sizeof(serv))) {
            LOGE("bufferevent_socket_connect faild \n");
            break;
        }

        bufferevent_setcb(context->bev, _socket_read_cb,
                _socket_write_cb, _socket_event_cb, context);
        bufferevent_enable(context->bev, EV_READ | EV_PERSIST);

        if (0 != pthread_create(&context->id, NULL,
                    _event_base_dispatch_loop, context)) {
            LOGE("pthread_create faild \n");
            break;
        }

        return 0;
    } while(0);

    _libevent_destroy(context);

    return -1;
}

static void _libevent_destroy(server_libevent_context_t *context)
{
    if (context->id) {
        event_base_loopexit(context->base, NULL);
        pthread_join(context->id, NULL);
    }

    if (context->bev) {
        bufferevent_free(context->bev);
    }

    if (context->base) {
        event_base_free(context->base);
    }
}

void *server_libevent_create(ServerConfig_t *server_config)
{
    LOGT("%s:%d \n", __func__, __LINE__);

    server_libevent_context_t *context = NULL;

    do {
        context = malloc(sizeof(*context));
        if (!context) {
            LOGE("malloc faild \n");
            break;
        }
        memset(context, '\0', sizeof(*context));

        memcpy(&context->cb, &server_config->cb, sizeof(server_config->cb));

        if (0 != _libevent_create(context, server_config)) {
            LOGE("_libevent_create faild \n");
            break;
        }

        return context;
    } while(0);

    server_libevent_destroy(context);

    return NULL;
}

void server_libevent_destroy(void *handle)
{
    LOGT("%s:%d \n", __func__, __LINE__);

    server_libevent_context_t *context = handle;

    if (context->base) {
        _libevent_destroy(context);
    }

    free(context);
}

