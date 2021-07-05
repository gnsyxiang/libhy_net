/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    server_com.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 14:57
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 14:57
 */
#ifndef __LIBHY_SERVER_PROTOCOL_INCLUDE_SERVER_COM_H_
#define __LIBHY_SERVER_PROTOCOL_INCLUDE_SERVER_COM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

enum {
    SERVER_STATE_DISCONNECT = (uint32_t)(0x1 << 0),
    SERVER_STATE_CONNECTED  = (uint32_t)(0x1 << 1),

    SERVER_STATE_REGISTER   = (uint32_t)(0x1 << 2),
};

typedef struct {
    void (*state_cb)(int state, void *args);
    void (*data_cb)(void *data, size_t len, void *args);
    void *args;
} ServerCb_t;

typedef struct {
    char            *ip;
    uint16_t        port;

    ServerCb_t      cb;
} ServerConfig_t;

#ifdef __cplusplus
}
#endif

#endif

