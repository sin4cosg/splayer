/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


static spv_log_t spv_log;
static const char *levels[] = {
    "verbose", "debug", "info", "warning", "error",
};


static void spv_log_core(spv_uint_t level, spv_log_t *log, spv_err_t err,
                         const char *fmt, va_list args);


spv_log_t *
spv_log_init(const char *prefix)
{
    return &spv_log;
}


static void
spv_log_core(spv_uint_t level, spv_log_t *log, spv_err_t err,
             const char *fmt, va_list args)
{
    char log_msg[MAX_LOG_STR];
    size_t len, max;

    spv_memzero(log_msg, MAX_LOG_STR);
    len = 0;
    max = MAX_LOG_STR - 1;

    len += spv_snprintf(log_msg + len, max - len, "[%s] ", levels[level]);
    len += spv_vsnprintf(log_msg + len, max - len, fmt, args);

    printf("%s\n", log_msg);
}


void
spv_log_debug(spv_log_t *log, spv_err_t err,
              const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    spv_log_core(1, log, err, fmt, args);
    va_end(args);
}


void
spv_log_error(spv_log_t *log, spv_err_t err,
              const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    spv_log_core(4, log, err, fmt, args);
    va_end(args);
}
