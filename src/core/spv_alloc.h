/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_ALLOC_H
#define SPV_ALLOC_H


#include <spv_config.h>
#include <spv_core.h>


#define spv_free            free


void *spv_alloc(size_t size, spv_log_t *log);
void *spv_calloc(size_t size, spv_log_t *log);


#endif  // SPV_ALLOC_H
