/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_THREAD_MUTEX_H
#define SPV_THREAD_MUTEX_H


#include <spv_config.h>
#include <spv_core.h>


typedef pthread_mutex_t     spv_thread_mutex_t;

spv_int_t spv_thread_mutex_create(spv_thread_mutex_t *mtx, spv_log_t *log);
spv_int_t spv_thread_mutex_destroy(spv_thread_mutex_t *mtx, spv_log_t *log);
spv_int_t spv_thread_mutex_lock(spv_thread_mutex_t *mtx, spv_log_t *log);
spv_int_t spv_thread_mutex_unlock(spv_thread_mutex_t *mtx, spv_log_t *log);


#endif  // SPV_THREAD_MUTEX_H
