/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


spv_int_t
spv_thread_cond_create(spv_thread_cond_t *cond, spv_log_t *log)
{
    spv_err_t err;

    err = pthread_cond_init(cond, NULL);
    if (err != 0) {
        spv_log_error(log, err, "pthread_cond_init() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}


spv_int_t
spv_thread_cond_destroy(spv_thread_cond_t *cond, spv_log_t *log)
{
    spv_err_t err;

    err = pthread_cond_destroy(cond);
    if (err != 0) {
        spv_log_error(log, err, "pthread_cond_destroy() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}


spv_int_t
spv_thread_cond_signal(spv_thread_cond_t *cond, spv_log_t *log)
{
    spv_err_t err;

    err = pthread_cond_signal(cond);
    if (err != 0) {
        spv_log_error(log, err, "pthread_cond_signal() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}


spv_int_t
spv_thread_cond_wait(spv_thread_cond_t *cond, spv_thread_mutex_t *mtx, spv_log_t *log)
{
    spv_err_t err;
    
    err = pthread_cond_wait(cond, mtx);
    if (err != 0) {
        spv_log_error(log, err, "pthread_cond_wait() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}
