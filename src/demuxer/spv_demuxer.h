/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_DEMUXER_H
#define SPV_DEMUXER_H


#include <spv_config.h>
#include <spv_core.h>


extern spv_module_t spv_demuxer_core_module;


typedef struct {
    char *url;
} spv_demuxer_public_data_t;


typedef struct {
    spv_int_t (*open)(spv_cycle_t *cycle, const char *url);
    spv_int_t (*read)(spv_cycle_t *cycle, void *buffer, const spv_uint_t size);
    spv_int_t (*seek)(spv_cycle_t *cycle, const spv_time_t seek_pos, const spv_int_t whence);
    spv_int_t (*close)(spv_cycle_t *cycle);
} spv_demuxer_actions_t;


typedef struct {
    char *name;
    spv_uint_t priv_data_size;
    spv_demuxer_actions_t actions;
} spv_demuxer_module_t;


#endif  // SPV_DEMUXER_H
