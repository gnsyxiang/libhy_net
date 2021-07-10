/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    hy_net.h
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
#ifndef __LIBHY_NET_INCLUDE_HY_NET_H_
#define __LIBHY_NET_INCLUDE_HY_NET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

typedef struct {
    void (*data_cb)(void *data, size_t len, void *args);
    void *args;
} HyNetConfigSave_t;

typedef struct {
    char        *ip;
    uint16_t    port;

    HyNetConfigSave_t config_save;
} HyNetConfig_t;

void *HyNetCreate(HyNetConfig_t *net_config);
void HyNetDestroy(void *handle);

int HyNetProcess(void *handle);

int HyNetWrite(void *handle, void *data, size_t len);

#ifdef __cplusplus
}
#endif

#endif

