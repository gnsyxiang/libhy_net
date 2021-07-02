/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    main.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    18/03 2021 20:22
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        18/03 2021      create the file
 * 
 *     last modified: 18/03 2021 20:22
 */
#include <stdio.h>

#include "hy_server_protocol.h"

#include "hy_hal/hy_time.h"

#include "hy_utils/hy_log.h"
#define ALONE_DEBUG 1

static void _data_cb(int type, void *data, uint32_t len)
{
    LOGD("data: %s \n", data);
}

int main(int argc, char const* argv[])
{
    HyLogCreate(HY_LOG_LEVEL_ALL, 1024, "./res/config/log4cplus.rc");

    HyServerProtocolConfig_t server_protocol_config;
    server_protocol_config.type = HY_SERVER_PROTOCOL_TYPE_JSON;
    server_protocol_config.ip   = "192.168.1.57";
    server_protocol_config.port = 9999;
    server_protocol_config.cb   = _data_cb;

    void *handle = HyServerProtocolCreate(&server_protocol_config);
    if (!handle) {
        LOGE("HyServerProtocolCreate faild \n");
        return -1;
    }

    while (1) {
        HyTimeDelayMs(1000);
    }

    HyServerProtocolDestroy(handle);
    HyLogDestroy();

    return 0;
}

