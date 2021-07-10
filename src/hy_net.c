/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    hy_net.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/07 2021 14:52
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/07 2021      create the file
 * 
 *     last modified: 02/07 2021 14:52
 */
#include <stdio.h>

#include "hy_net.h"
#include "protocol.h"

#include "hy_utils/hy_utils.h"
#include "hy_utils/hy_log.h"

#define ALONE_DEBUG 1

void *HyNetCreate(HyNetConfig_t *net_config)
{
    LOGT("%s:%d \n", __func__, __LINE__);

    JUDGE_NULL_RET(!net_config, NULL);
    return protocol_create(net_config);
}

void HyNetDestroy(void *handle)
{
    LOGT("%s:%d \n", __func__, __LINE__);

    JUDGE_NULL(!handle);
    protocol_destroy(handle);
}

int HyNetProcess(void *handle)
{
    JUDGE_NULL_RET(!handle, -1);
    return protocol_process(handle);
}

int HyNetWrite(void *handle, void *data, size_t len)
{
    JUDGE_NULL_RET(!handle || !data, -1);
    return protocol_write(handle, data, len);
}

