/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    server_libevent.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 14:33
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 14:33
 */
#ifndef __LIBHY_SERVER_PROTOCOL_INCLUDE_SERVER_LIBEVENT_H_
#define __LIBHY_SERVER_PROTOCOL_INCLUDE_SERVER_LIBEVENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "server_common.h"
#include "protocol_common.h"

void *server_libevent_create(ServerCommonConfig_t *server_config);
void server_libevent_destroy(ProtocolContext_t *context);

int server_libevent_write(ProtocolContext_t *context, void *data, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif

