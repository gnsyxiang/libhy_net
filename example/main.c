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
#include <unistd.h>

#include "hy_net.h"

#include "hy_utils/hy_log.h"
#define ALONE_DEBUG 1

static void _data_cb(void *data, size_t len, void *args)
{
    LOGD("len: %d, data: %s \n", len, data);
}

static void *_connect_server(void)
{
    HyNetConfig_t net_config;
    net_config.ip           = "192.168.1.57";
    net_config.port         = 7809;

    net_config.config_save.data_cb  = _data_cb;
    net_config.config_save.args     = NULL;

    void *handle = HyNetCreate(&net_config);
    if (!handle) {
        LOGE("HyNetCreate faild \n");
        return NULL;
    }
    return handle;
}

int main(int argc, char const* argv[])
{
    HyLogCreate(HY_LOG_LEVEL_ALL, 1024, "./res/config/log4cplus.rc");

    void *handle = _connect_server();

    while (1) {
        sleep(1);
    }

    int cnt = 0;
    while (cnt < 3) {
        if (0 != HyNetProcess(handle)) {
            LOGI("disconnect server \n");

            handle = _connect_server();
            cnt++;
        }
    }

    HyNetDestroy(handle);

    HyLogDestroy();

    return 0;
}

