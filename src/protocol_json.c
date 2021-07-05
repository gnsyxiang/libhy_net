/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    protocol_json.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 15:29
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 15:29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "protocol_json.h"
#include "server_com.h"
#include "server_libevent.h"

#include "hy_utils/hy_log.h"
#define ALONE_DEBUG 1

int ProtocolJsonWrite(ProtocolContext_t *context, void *data, size_t len)
{
    return server_libevent_write(context->handle, data, len);
}

static void _handle_data_cb(void *data, size_t len, void *args)
{
    ProtocolContext_t *context = args;

    if (context->cb) {
        context->cb(1, data, len, context->args);
    }
}

static void _handle_state_cb(int state, void *args)
{
    ProtocolContext_t *context = args;

    LOGD("------------%d \n", state);

    if (context) {
        context->state = state;
    }
}

void *ProtocolJsonCreate(HyServerProtocolConfig_t *server_protocol_config)
{
    LOGT("%s:%d \n", __func__, __LINE__);

    ProtocolContext_t *context = NULL;

    do {
        context = malloc(sizeof(*context));
        if (!context) {
            LOGE("malloc faild \n");
            break;
        }
        memset(context, '\0', sizeof(*context));

        context->type   = server_protocol_config->type;
        context->cb     = server_protocol_config->cb;
        context->args   = server_protocol_config->args;

        ServerConfig_t server_config;
        server_config.ip            = server_protocol_config->ip;
        server_config.port          = server_protocol_config->port;
        server_config.cb.state_cb   = _handle_state_cb;
        server_config.cb.data_cb    = _handle_data_cb;
        server_config.cb.args       = context;

        context->handle = server_libevent_create(&server_config);
        if (!context->handle) {
            LOGE("server_libevent_create faild \n");
            break;
        }

        return context;
    } while (0);

    ProtocolJsonDestroy(context);

    return NULL;
}

void ProtocolJsonDestroy(ProtocolContext_t *context)
{
    LOGT("%s:%d \n", __func__, __LINE__);

    if (context->handle) {
        server_libevent_destroy(context->handle);
    }

    free(context);
}

int ProtocolJsonProcess(ProtocolContext_t *context)
{
    if (context->state & SERVER_STATE_CONNECTED) {
        if (context->state & SERVER_STATE_REGISTER) {
        } else {
        }
    }

    if (context->state & SERVER_STATE_DISCONNECT) {
        return -1;
    } else {
        return 0;
    }
}

