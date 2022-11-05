/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


void
spv_queue_set_nonblock(spv_queue_t *queue)
{
    queue->nonblock = 1;
}


void
spv_queue_set_block(spv_queue_t *queue)
{
    queue->nonblock = 0;
}


spv_queue_t *
spv_queue_create(spv_uint_t type, size_t max_size, spv_log_t *log)
{
    spv_err_t err;
    spv_queue_t *queue;

    queue = (spv_queue_t *) spv_calloc(sizeof(spv_queue_t), log);
    if (queue == NULL) {
        return NULL;
    }
    INIT_LIST_HEAD(&queue->list);

    err = spv_thread_mutex_create(&queue->mtx, log);
    if (err == SPV_OK) {
        err = spv_thread_cond_create(&queue->cond, log);
        if (err == SPV_OK) {
            queue->type = type;
            queue->max_size = max_size;
            queue->count = 0;
            queue->nonblock = 0;
            return queue;
        }
        spv_thread_destroy(&queue->mtx, log);
    }

    spv_free(queue);
    return NULL;
}


void
spv_queue_destroy(spv_queue_t *queue, spv_log_t *log)
{
    spv_thread_cond_destroy(&queue->cond, log);
    spv_thread_mutex_destroy(&queue->mtx, log);
    free(queue);
}


void
spv_queue_put(spv_queue_t *queue, spv_log_t *log, spv_queue_node_t *data)
{
    spv_thread_mutex_lock(&queue->mtx, log);

    while (queue->count > queue->max_size - 1)
        spv_thread_cond_wait(&queue->cond, &queue->mtx, log);

    spv_list_add_tail(&data->list, &queue->list);
    queue->count++;

    spv_thread_mutex_unlock(&queue->mtx, log);
    spv_thread_cond_signal(&queue->cond, log);
}


spv_queue_node_t *
spv_queue_get(spv_queue_t *queue, spv_log_t *log)
{
    spv_queue_node_t *node;

    spv_thread_mutex_lock(&queue->mtx, log);

    while (queue->count == 0)
        spv_thread_cond_wait(&queue->cond, &queue->mtx, log);

    node = spv_list_first_entry(&queue->list, spv_queue_node_t, list);
    spv_list_del(&node->list);
    queue->count--;

    spv_thread_mutex_unlock(&queue->mtx, log);
    spv_thread_cond_signal(&queue->cond, log);

    return node;
}
