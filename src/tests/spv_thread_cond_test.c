/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


static spv_thread_mutex_t *mtx = NULL;
static spv_thread_cond_t *cond = NULL;
static spv_int_t count = 0;


static void *
increment_count(void *arg)
{
    spv_thread_mutex_lock(mtx, NULL);
    spv_log_debug(NULL, 0, "increment_count get mutex");

    if (count == 0) {
        spv_log_debug(NULL, 0, "increment_count before signal");
        spv_thread_cond_signal(cond, NULL);
        spv_log_debug(NULL, 0, "increment_count after signal");
    }

    count++;
    spv_thread_mutex_unlock(mtx, NULL);

    return NULL;
}


static void *
decrement_count(void *arg)
{
    spv_thread_mutex_lock(mtx, NULL);
    spv_log_debug(NULL, 0, "decrement_count get mutex");

    while (count == 0) {
        spv_log_debug(NULL, 0, "decrement_count before wait");
        spv_thread_cond_wait(cond, mtx, NULL);
        spv_log_debug(NULL, 0, "decrement_count after wait");
    }

    count--;
    spv_thread_mutex_unlock(mtx, NULL);

    return NULL;
}


void
SPV_THREAD_COND_TEST()
{
    mtx = spv_calloc(sizeof(spv_thread_mutex_t), NULL);
    cond = spv_calloc(sizeof(spv_thread_cond_t), NULL);
    spv_thread_mutex_create(mtx, NULL);
    spv_thread_cond_create(cond, NULL);
    spv_thread_t worker1, worker2;

    spv_thread_create(&worker1, decrement_count, NULL, NULL);
    sleep(1);
    spv_thread_create(&worker2, increment_count, NULL, NULL);
    sleep(1);
    spv_thread_destroy(&worker1, NULL);
    spv_thread_destroy(&worker2, NULL);

    spv_thread_cond_destroy(cond, NULL);
    spv_thread_mutex_destroy(mtx, NULL);
}
