/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_THREAD_COND_H
#define SPV_THREAD_COND_H


#include <spv_config.h>
#include <spv_core.h>


typedef pthread_cond_t      spv_thread_cond_t;


spv_int_t spv_thread_cond_create(spv_thread_cond_t *cond, spv_log_t *log);
spv_int_t spv_thread_cond_destroy(spv_thread_cond_t *cond, spv_log_t *log);
spv_int_t spv_thread_cond_signal(spv_thread_cond_t *cond, spv_log_t *log);
spv_int_t spv_thread_cond_wait(spv_thread_cond_t *cond, spv_thread_mutex_t *mtx, spv_log_t *log);


#endif  // SPV_THREAD_COND_H
