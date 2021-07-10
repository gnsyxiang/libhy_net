/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    protocol_json.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    09/07 2021 20:29
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        09/07 2021      create the file
 * 
 *     last modified: 09/07 2021 20:29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "protocol.h"
#include "net.h"

#include "hy_utils/hy_log.h"
#define ALONE_DEBUG 1

typedef struct {
    HyNetConfigSave_t   up_config;
    void                *down_handle;

    net_state_t         net_state;
} _protocol_context_t;

int protocol_process(void **handle)
{
    return 0;
}

int protocol_write(void *handle, void *data, size_t len)
{
    return net_write(handle, data, len);
}

static void _handle_data_cb(void *data, size_t len, void *args)
{
    _protocol_context_t *context = args;
    if (context && context->up_config.data_cb) {
        context->up_config.data_cb(data, len, context->up_config.args);
    }
}

static void _handle_state_cb(net_state_t state, void *args)
{
    LOGT("net state: %d \n", state);

    _protocol_context_t *context = args;
    context->net_state = state;
}

void protocol_destroy(void *handle)
{
    LOGT("%s:%d \n", __func__, __LINE__);

    _protocol_context_t *context = handle;
    if (context->down_handle) {
        net_destroy(context->down_handle);
    }

    free(context);
}

void *protocol_create(HyNetConfig_t *NetConfig)
{
    LOGT("%s:%d \n", __func__, __LINE__);

    _protocol_context_t *context = NULL;

    do {
        context = malloc(sizeof(*context));
        if (!context) {
            LOGE("malloc faild \n");
            break;
        }
        memset(context, '\0', sizeof(*context));

        memcpy(&context->up_config, &NetConfig->config_save,
                sizeof(context->up_config));

        net_config_t net_config;
        net_config.ip            = NetConfig->ip;
        net_config.port          = NetConfig->port;
        net_config.cb.state_cb   = _handle_state_cb;
        net_config.cb.data_cb    = _handle_data_cb;
        net_config.cb.args       = context;

        context->down_handle = net_create(&net_config);
        if (!context->down_handle) {
            LOGE("net create faild \n");
            break;
        }

        return context;
    } while (0);

    protocol_destroy(context);

    return NULL;
}

