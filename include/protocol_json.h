/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    protocol_json.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 15:06
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 15:06
 */
#ifndef __LIBHY_SERVER_INCLUDE_PROTOCOL_JSON_H_
#define __LIBHY_SERVER_INCLUDE_PROTOCOL_JSON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "hy_server_protocol.h"
#include "protocol_com.h"

void *protocol_json_create(HyServerProtocolConfig_t *server_protocol_config);
void protocol_json_destroy(ProtocolContext_t *context);

int protocol_json_write(ProtocolContext_t *context, void *data, size_t len);

#ifdef __cplusplus
}
#endif

#endif

