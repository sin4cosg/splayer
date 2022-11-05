/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


typedef struct {
    AVFormatContext *fmt_ctx;
} spv_demuxer_lavf_priv_t;


static spv_int_t spv_demuxer_lavf_module_init(spv_cycle_t *cycle, spv_uint_t index);
static spv_int_t spv_demuxer_lavf_actions_open(spv_cycle_t *cycle, const char *url);
static spv_int_t spv_demuxer_lavf_actions_read(spv_cycle_t *cycle, void *buffer, const spv_uint_t size);
static spv_int_t spv_demuxer_lavf_actions_seek(spv_cycle_t *cycle, const spv_time_t seek_pos, const spv_int_t whence);
static spv_int_t spv_demuxer_lavf_actions_close(spv_cycle_t *cycle);


static spv_demuxer_module_t spv_demuxer_lavf_module_ctx = {
    "demuxer_lavf",
    sizeof(spv_demuxer_lavf_priv_t),
    spv_demuxer_lavf_actions_open,
    spv_demuxer_lavf_actions_read,
    spv_demuxer_lavf_actions_seek,
    spv_demuxer_lavf_actions_close,
};


spv_module_t spv_demuxer_lavf_module = {
    SPV_DEMUXER_MODULE,
    &spv_demuxer_lavf_module_ctx,
    "demuxer_lavf",
    NULL,
};


static spv_int_t
spv_demuxer_lavf_module_init(spv_cycle_t *cycle, spv_uint_t index)
{
    FUNC_TRACE

    return SPV_OK;
}


static spv_int_t
spv_demuxer_lavf_actions_open(spv_cycle_t *cycle, const char *url)
{
    FUNC_TRACE

    return SPV_OK;
}


static spv_int_t
spv_demuxer_lavf_actions_read(spv_cycle_t *cycle, void *buffer, const spv_uint_t size)
{
    FUNC_TRACE

    return SPV_OK;
}


static spv_int_t
spv_demuxer_lavf_actions_seek(spv_cycle_t *cycle, const spv_time_t seek_pos, const spv_int_t whence)
{
    FUNC_TRACE

    return SPV_OK;
}


static spv_int_t
spv_demuxer_lavf_actions_close(spv_cycle_t *cycle)
{
    FUNC_TRACE

    return SPV_OK;
}
