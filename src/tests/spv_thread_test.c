/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


static void *
task(void *arg)
{
    spv_log_debug(NULL, 0, "Task running...");

    return NULL;
}


void
SPV_THREAD_TEST()
{
    spv_thread_t worker;
    spv_thread_create(&worker, task, NULL, NULL);
    spv_thread_destroy(&worker, NULL);
}
