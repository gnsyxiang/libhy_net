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
#include <stdlib.h>
#include <string.h>

#include "hy_net.h"

#include "hy_utils/hy_module.h"
#include "hy_utils/hy_log.h"
#define ALONE_DEBUG 1

typedef struct {
    void *log_handle;
    void *net_handle;
} _main_context_t;

static void _data_cb(void *data, size_t len, void *args)
{
    LOGD("len: %d, data: %s \n", len, data);
}

static void _module_destroy(_main_context_t *context)
{
    // note: 增加或删除要同步到module_create_t中
    module_destroy_t module[] = {
        {"log",     context->log_handle,    HyLogDestroy},
        {"net",     context->net_handle,    HyNetDestroy},
    };

    RUN_DESTROY(module);
}

static _main_context_t *_module_create(void)
{
    _main_context_t *context = malloc(sizeof(*context));
    if (!context) {
        LOGE("malloc faild \n");
        return NULL;
    }
    memset(context, '\0', sizeof(*context));

    HyLogConfig_t log_config;
    log_config.buf_len = 512;
    log_config.level = HY_LOG_LEVEL_INFO;
    log_config.config_file = "./res/config/log4cplus.rc";

    HyNetConfig_t net_config;
    net_config.ip           = "192.168.1.57";
    net_config.port         = 7809;

    net_config.config_save.data_cb  = _data_cb;
    net_config.config_save.args     = NULL;

    // note: 增加或删除要同步到module_destroy_t中
    module_create_t module[] = {
        {"log",     &context->log_handle,   &log_config,    (create_t)HyLogCreate,  HyLogDestroy},
        {"net",     &context->net_handle,   &net_config,    (create_t)HyNetCreate,  HyNetDestroy},
    };

    RUN_CREATE(module);

    return context;
}

int main(int argc, char const* argv[])
{
    _main_context_t *context = _module_create();
    if (!context) {
        LOGE("_module_create faild \n");
        return -1;
    }

    while (1) {
        sleep(1);
    }

    _module_destroy(context);

    return 0;
}

