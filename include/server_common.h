/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    server_common.h
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
#ifndef __LIBHY_SERVER_PROTOCOL_INCLUDE_SERVER_COMMON_H_
#define __LIBHY_SERVER_PROTOCOL_INCLUDE_SERVER_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

typedef void (*ServerCommonCb_t)(int type, void *data, uint32_t len);

typedef struct {
    char        *ip;
    uint16_t    port;

    ServerCommonCb_t    cb;
} ServerCommonConfig_t;

#ifdef __cplusplus
}
#endif

#endif

