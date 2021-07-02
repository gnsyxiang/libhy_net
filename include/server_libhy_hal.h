/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    server_libhy_hal.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 15:01
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 15:01
 */
#ifndef __LIBHY_SERVER_PROTOCOL_INCLUDE_SERVER_LIBHY_HAL_H_
#define __LIBHY_SERVER_PROTOCOL_INCLUDE_SERVER_LIBHY_HAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "server_common.h"

void *server_libhy_hal_create(ServerCommonConfig_t *server_config);
void server_libhy_hal_destroy(void *handle);

int server_libhy_hal_write(void *handle, void *data, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif

