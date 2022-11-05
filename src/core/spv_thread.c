/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


spv_int_t
spv_thread_create(spv_thread_t *tid, void *handler, void *args, spv_log_t *log)
{
    spv_err_t err;
    pthread_attr_t attr;

    err = pthread_attr_init(&attr);
    if (err != 0) {
        spv_log_error(log, err, "pthread_attr_init() failed");
        return SPV_ERROR;
    }

    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    if (err != 0) {
        spv_log_error(log, err, "pthread_attr_setdetachstate() failed");
        return SPV_ERROR;
    }

    err = pthread_create(tid, &attr, handler, args);
    if (err != 0) {
        spv_log_error(log, err, "pthread_create() failed");
        return SPV_ERROR;
    }

    err = pthread_attr_destroy(&attr);
    if (err != 0) {
        spv_log_error(log, err, "pthread_attr_destroy() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}


spv_int_t
spv_thread_destroy(spv_thread_t *tid, spv_log_t *log)
{
    spv_err_t err;

    err = pthread_join(*tid, NULL);
    if (err != 0) {
        spv_log_error(log, err, "pthread_join() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}
