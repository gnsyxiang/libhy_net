/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    net_com.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    10/07 2021 08:16
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        10/07 2021      create the file
 * 
 *     last modified: 10/07 2021 08:16
 */
#ifndef __LIBHY_NET_INCLUDE_NET_NET_COM_H_
#define __LIBHY_NET_INCLUDE_NET_NET_COM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

typedef enum {
    NET_STATE_DISCONNECT,
    NET_STATE_CONNECTING,
    NET_STATE_CONNECTED,

    NET_STATE_MAX,
} net_state_t;

typedef struct {
    void (*state_cb)(net_state_t state, void *args);
    void (*data_cb)(void *data, size_t len, void *args);
    void *args;
} net_cb_t;

typedef struct {
    char        *ip;
    uint16_t    port;

    net_cb_t    cb;
} net_config_t;

void *net_create(net_config_t *net_config);
void net_destroy(void *handle);

int net_process(void *handle);
int net_write(void *handle, void *data, size_t len);

#ifdef __cplusplus
}
#endif

#endif

