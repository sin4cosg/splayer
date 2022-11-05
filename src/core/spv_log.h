/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_LOG_H
#define SPV_LOG_H


#include <spv_config.h>
#include <spv_core.h>


#define MAX_LOG_STR     2048


struct spv_log_s {
    spv_uint_t      log_level;
};


spv_log_t *spv_log_init(const char *prefix);
void spv_log_debug(spv_log_t *log, spv_err_t err,
                   const char *fmt, ...);
void spv_log_error(spv_log_t *log, spv_err_t err,
                   const char *fmt, ...);


#define FUNC_TRACE                                                          \
    do {                                                                    \
        spv_log_debug(cycle->log, 0, "%s", __FUNCTION__);                   \
    } while (0);


#endif  // SPV_LOG_H
