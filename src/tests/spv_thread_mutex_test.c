/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


static void *
task(void *arg)
{
    spv_thread_mutex_t *mtx = (spv_thread_mutex_t *) arg;

    spv_thread_mutex_lock(mtx, NULL);
    for (int i = 0; i < 3; i++) {
        spv_log_debug(NULL, 0, "[%#lx] value of count: %d", pthread_self(), i);
    }
    spv_thread_mutex_unlock(mtx, NULL);

    return NULL;
}


void
SPV_THREAD_MUTEX_TEST()
{
    spv_thread_mutex_t mtx;
    spv_thread_mutex_create(&mtx, NULL);

    int thread_num = 5;
    spv_thread_t workers[thread_num];
    for (int i = 0; i < thread_num; i++) {
        spv_thread_create(&workers[i], task, &mtx, NULL);
    }
    for (int i = 0; i < thread_num; i++) {
        spv_thread_destroy(&workers[i], NULL);
    }

    spv_thread_mutex_destroy(&mtx, NULL);
}
