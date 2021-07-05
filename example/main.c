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

static void _data_cb(int type, void *data, size_t len, void *args)
{
    LOGD("len: %d, data: %s \n", len, data);
}

int main(int argc, char const* argv[])
{
    HyLogCreate(HY_LOG_LEVEL_ALL, 1024, "./res/config/log4cplus.rc");

    HyServerProtocolConfig_t server_protocol_config;
    server_protocol_config.ip           = "192.168.1.57";
    server_protocol_config.port         = 9999;

    server_protocol_config.config_save.type     = HY_SERVER_PROTOCOL_TYPE_JSON;
    server_protocol_config.config_save.data_cb  = _data_cb;
    server_protocol_config.config_save.args     = NULL;

    void *handle = HyServerProtocolCreate(&server_protocol_config);
    if (!handle) {
        LOGE("HyServerProtocolCreate faild \n");
        return -1;
    }

    while (1) {
        // HyTimeDelayMs(1000);

        if (0 != HyServerProtocolProcess(handle)) {
            LOGI("disconnect server \n");

            break;
        }
    }

    HyServerProtocolDestroy(handle);
    HyLogDestroy();

    return 0;
}

