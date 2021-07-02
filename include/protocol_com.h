/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    protocol_com.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 15:19
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 15:19
 */
#ifndef __LIBHY_SERVER_INCLUDE_PROTOCOL_COM_H_
#define __LIBHY_SERVER_INCLUDE_PROTOCOL_COM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "hy_server_protocol.h"

typedef struct {
    HyServerProtocolType_t  type;

    void                    *handle;
    HyServerProtocolCb_t    cb;
    void                    *args;
} ProtocolContext_t;

#ifdef __cplusplus
}
#endif

#endif

