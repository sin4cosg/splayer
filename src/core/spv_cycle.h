/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_CYCLE_H
#define SPV_CYCLE_H


#include <spv_config.h>
#include <spv_core.h>


struct spv_cycle_s {
    void *ctx;
    spv_log_t *log;
    spv_module_t **modules;
    spv_uint_t modules_n;
    spv_queue_t *video_packet_queue;
    spv_queue_t *video_frame_queue;
};


spv_cycle_t *spv_init_cycle(spv_cycle_t *old_cycle);


#endif  // SPV_CYCLE_H
