/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    hy_server_protocol.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 14:35
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 14:35
 */
#ifndef __LIBHY_SERVER_PROTOCOL_INCLUDE_HY_SERVER_PROTOCOL_H_
#define __LIBHY_SERVER_PROTOCOL_INCLUDE_HY_SERVER_PROTOCOL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

typedef enum {
    HY_SERVER_PROTOCOL_TYPE_JSON,
    HY_SERVER_PROTOCOL_TYPE_STRUCT,

    HY_SERVER_PROTOCOL_TYPE_MAX,
} HyServerProtocolType_t;

typedef void (*HyServerProtocolCb_t)(int type, void *data, uint32_t len);

typedef struct {
    HyServerProtocolType_t  type;

    char        *ip;
    uint16_t    port;

    HyServerProtocolCb_t cb;
} HyServerProtocolConfig_t;

void *HyServerProtocolCreate(HyServerProtocolConfig_t *server_protocol_config);
void HyServerProtocolDestroy(void *handle);

int HyServerProtocolWrite(void *handle, void *data, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
