/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_THREAD_H
#define SPV_THREAD_H


#include <spv_config.h>
#include <spv_core.h>


typedef pthread_t   spv_thread_t;


spv_int_t spv_thread_create(spv_thread_t *tid, void *handler, void *args, spv_log_t *log);
spv_int_t spv_thread_destroy(spv_thread_t *tid, spv_log_t *log);


#endif  // SPV_THREAD_H
