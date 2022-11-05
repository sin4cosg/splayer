/*
 * Copyright (C) SUMMER
 */


#include <splayer.h>
#include <spv_config.h>
#include <spv_core.h>


int
main(int argc, char *const *argv)
{
    spv_log_debug(NULL, 0, "SPLAYER VERSION: %s", SPLAYER_VER);

#if 0
    SPV_THREAD_TEST();
    SPV_THREAD_MUTEX_TEST();
    SPV_THREAD_COND_TEST();
    SPV_LIST_TEST();
    SPV_QUEUE_TEST();
#endif

    spv_cycle_t *cycle, init_cycle;
    spv_log_t *log;

    if (!(log = spv_log_init(NULL))) {
        return SPV_ERROR;
    }

    spv_memzero(&init_cycle, sizeof(spv_cycle_t));
    init_cycle.log = log;

    cycle = spv_init_cycle(&init_cycle);
    if (cycle == NULL) {
        spv_log_error(log, 0, "spv_init_cycle() failed");
        return SPV_ERROR;
    }

    return 0;
}
