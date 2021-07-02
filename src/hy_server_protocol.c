/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    hy_server_protocol.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 14:52
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 14:52
 */
#include <stdio.h>

#include "hy_server_protocol.h"

#include "protocol_common.h"
#include "protocol_json.h"
#include "protocol_struct.h"

#include "hy_utils/hy_log.h"
#define ALONE_DEBUG 1

void *HyServerProtocolCreate(HyServerProtocolConfig_t *server_protocol_config)
{
    if (!server_protocol_config) {
        LOGE("the param is NULL \n");
        return NULL;
    }

    typedef void *(*handle_cb_t)(HyServerProtocolConfig_t *server_protocol_config);
    handle_cb_t handle_cb[HY_SERVER_PROTOCOL_TYPE_MAX] = {
        protocol_json_create,
    };

    return handle_cb[server_protocol_config->type](server_protocol_config);
}

void HyServerProtocolDestroy(void *handle)
{
    if (!handle) {
        LOGE("the param is NULL \n");
        return ;
    }

    typedef void (*handle_cb_t)(ProtocolContext_t *context);
    handle_cb_t handle_cb[HY_SERVER_PROTOCOL_TYPE_MAX] = {
        protocol_json_destroy,
    };

    ProtocolContext_t *context = handle;
    handle_cb[context->type](context);
}

int HyServerProtocolWrite(void *handle, void *data, uint32_t len)
{
    if (!handle || !data) {
        LOGE("the param is error \n");
        return -1;
    }

    typedef int (*handle_cb_t)(ProtocolContext_t *context, void *data, uint32_t len);
    handle_cb_t handle_cb[HY_SERVER_PROTOCOL_TYPE_MAX] = {
        protocol_json_write,
    };

    ProtocolContext_t *context = handle;
    return handle_cb[context->type](context, data, len);
}

