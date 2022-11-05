/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


spv_int_t
spv_thread_mutex_create(spv_thread_mutex_t *mtx, spv_log_t *log)
{
    spv_err_t err;
    pthread_mutexattr_t attr;

    err = pthread_mutexattr_init(&attr);
    if (err != 0) {
        spv_log_error(log, err, "pthread_mutexattr_init() failed");
        return SPV_ERROR;
    }

    err = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
    if (err != 0) {
        spv_log_error(log, err, "pthread_mutexattr_settype() failed");
        return SPV_ERROR;
    }

    err = pthread_mutex_init(mtx, &attr);
    if (err != 0) {
        spv_log_error(log, err, "pthread_mutex_init() failed");
        return SPV_ERROR;
    }

    err = pthread_mutexattr_destroy(&attr);
    if (err != 0) {
        spv_log_error(log, err, "pthread_mutexattr_destroy() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}


spv_int_t
spv_thread_mutex_destroy(spv_thread_mutex_t *mtx, spv_log_t *log)
{
    spv_err_t err;

    err = pthread_mutex_destroy(mtx);
    if (err != 0) {
        spv_log_error(log, err, "pthread_mutex_destroy() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}


spv_int_t
spv_thread_mutex_lock(spv_thread_mutex_t *mtx, spv_log_t *log)
{
    spv_err_t err;

    err = pthread_mutex_lock(mtx);
    if (err != 0) {
        spv_log_error(log, err, "pthread_mutex_lock() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}


spv_int_t
spv_thread_mutex_unlock(spv_thread_mutex_t *mtx, spv_log_t *log)
{
    spv_err_t err;

    err = pthread_mutex_unlock(mtx);
    if (err != 0) {
        spv_log_error(log, err, "pthread_mutex_unlock() failed");
        return SPV_ERROR;
    }

    return SPV_OK;
}
