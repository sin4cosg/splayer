/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_QUEUE_H
#define SPV_QUEUE_H


#include <spv_config.h>
#include <spv_core.h>


typedef struct {
    struct list_head list;
    void *data;
} spv_queue_node_t;


struct spv_queue_s {
    spv_uint_t type;
    spv_uint_t nonblock;
    size_t max_size;
    size_t count;
    struct list_head list;
    spv_thread_mutex_t mtx;
    spv_thread_cond_t cond;
};


spv_queue_t *spv_queue_create(spv_uint_t type, size_t max_size, spv_log_t *log);
void spv_queue_destroy(spv_queue_t *queue, spv_log_t *log);
void spv_queue_put(spv_queue_t *queue, spv_log_t *log, spv_queue_node_t *data);
spv_queue_node_t *spv_queue_get(spv_queue_t *queue, spv_log_t *log);
void spv_queue_set_nonblock(spv_queue_t *queue);
void spv_queue_set_block(spv_queue_t *queue);


#endif  // SPV_QUEUE_H
