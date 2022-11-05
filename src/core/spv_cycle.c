/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


spv_cycle_t *
spv_init_cycle(spv_cycle_t *old_cycle)
{
    spv_log_t *log;
    spv_cycle_t *cycle;

    log = old_cycle->log;

    if (!(cycle = spv_calloc(sizeof(spv_cycle_t), log))) {
        return NULL;
    }

    cycle->log = log;

    if (spv_cycle_modules(cycle) != SPV_OK) {
        exit(1);
    }

    if (spv_init_modules(cycle) != SPV_OK) {
        exit(1);
    }

    cycle->video_packet_queue = spv_queue_create(0, 10, cycle->log);
    if (cycle->video_packet_queue == NULL) {
        exit(1);
    }

    cycle->video_frame_queue = spv_queue_create(1, 10, cycle->log);
    if (cycle->video_frame_queue == NULL) {
        exit(1);
    }

    return cycle;
}
