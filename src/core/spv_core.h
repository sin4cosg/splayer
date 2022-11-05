/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_CORE_H
#define SPV_CORE_H


typedef struct spv_log_s        spv_log_t;
typedef struct spv_cycle_s      spv_cycle_t;
typedef struct spv_module_s     spv_module_t;
typedef struct spv_queue_s      spv_queue_t;


#define SPV_OK               0
#define SPV_ERROR           -1


#define spv_inline              inline


#define SPV_MODULE              0x1fffffff
#define SPV_CORE_MODULE         0x2fffffff
#define SPV_DEMUXER_MODULE      0x3fffffff
#define SPV_DECODER_MODULE      0x4fffffff
#define SPV_RENDERER_MODULE     0x5fffffff


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>


#include <spv_log.h>
#include <spv_alloc.h>
#include <spv_string.h>
#include <spv_thread.h>
#include <spv_thread_mutex.h>
#include <spv_thread_cond.h>
#include <spv_module.h>
#include <spv_cycle.h>
#include <spv_list.h>
#include <spv_queue.h>


/* demuxer module */
#include <spv_demuxer.h>
#include <spv_demuxer_lavf_module.h>


/* For tests */
#include <spv_test.h>


#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *) 0)->MEMBER)
#define container_of(ptr, type, member) ({                      \
    void *__mptr = (void *)(ptr);                               \
    ((type *)(__mptr - offsetof(type, member)));                  \
})


#endif  // SPV_CORE_H
