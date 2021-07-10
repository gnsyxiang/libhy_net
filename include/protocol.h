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
#ifndef __LIBHY_NET_INCLUDE_PROTOCOL_JSON_PROTOCOL_JSON_H_
#define __LIBHY_NET_INCLUDE_PROTOCOL_JSON_PROTOCOL_JSON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "hy_net.h"

void *protocol_create(HyNetConfig_t *net_config);
void protocol_destroy(void *handle);

int protocol_process(void *handle);

int protocol_write(void *handle, void *data, size_t len);

#ifdef __cplusplus
}
#endif

#endif

