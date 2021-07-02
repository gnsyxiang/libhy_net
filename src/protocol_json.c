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
#include "server_common.h"
#include "server_libevent.h"

#include "hy_utils/hy_log.h"
#define ALONE_DEBUG 1

void *protocol_json_create(HyServerProtocolConfig_t *server_protocol_config)
{
    ProtocolContext_t *context = NULL;

    do {
        context = malloc(sizeof(*context));
        if (!context) {
            LOGE("malloc faild \n");
            break;
        }
        memset(context, '\0', sizeof(*context));

        context->type = server_protocol_config->type;

        ServerCommonConfig_t server_config;
        server_config.ip    = server_protocol_config->ip;
        server_config.port  = server_protocol_config->port;
        server_config.cb    = server_protocol_config->cb;

        context->handle = server_libevent_create(&server_config);
        if (!context->handle) {
            LOGE("server_libevent_create faild \n");
            break;
        }

        return context;
    } while (0);

    if (context) {
        if (context->handle) {
            server_libevent_destroy(context->handle);
        }

        free(context);
    }

    return NULL;
}

void protocol_json_destroy(ProtocolContext_t *context)
{
    if (context->handle) {
        server_libevent_destroy(context->handle);
    }

    free(context);
}

int protocol_json_write(ProtocolContext_t *context, void *data, uint32_t len)
{
    return server_libevent_write(context->handle, data, len);
}
