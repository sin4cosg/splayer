/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


static int quit = 0;
static size_t put_count = 0;
static size_t get_count = 0;
static spv_queue_t *queue;


static void *
prosumer_task(void *arg)
{
    while (put_count < 50) {
        spv_queue_node_t *node = (spv_queue_node_t *) spv_calloc(sizeof(spv_queue_node_t), NULL);
        spv_queue_put(queue, NULL, node);
        put_count++;
        spv_log_debug(NULL, 0, "prosumer_task running... put_cnt:%d", put_count);
    }
    quit = 1;

    return NULL;
}


static void *
consumer_task(void *arg)
{
    while (quit != 1) {
        spv_queue_node_t *node;
        node = spv_queue_get(queue, NULL);
        get_count++;
        spv_log_debug(NULL, 0, "consumer_task running... get_cnt:%d", get_count);
        free(node);
    }

    return NULL;
}


void
SPV_QUEUE_TEST()
{
    queue = spv_queue_create(0, 5, NULL);
    spv_thread_t prosumer_worker, consumer_worker;
    spv_thread_create(&prosumer_worker, prosumer_task, NULL, NULL);
    spv_thread_create(&consumer_worker, consumer_task, NULL, NULL);


    spv_thread_destroy(&prosumer_worker, NULL);
    spv_thread_destroy(&consumer_worker, NULL);
    spv_queue_destroy(queue, NULL);
}
