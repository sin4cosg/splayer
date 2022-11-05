/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


static void *demuxer_main_cycle(void *args);
static spv_int_t spv_demuxer_core_module_init(spv_cycle_t *cycle, spv_uint_t index);


spv_core_module_t spv_demuxer_core_module_ctx = {
    "demuxer_core",
    NULL,
    NULL,
};


spv_module_t spv_demuxer_core_module = {
    SPV_CORE_MODULE,
    &spv_demuxer_core_module_ctx,
    "demuxer_core",
    spv_demuxer_core_module_init,
};


static spv_int_t
spv_demuxer_core_module_init(spv_cycle_t *cycle, spv_uint_t index)
{
    FUNC_TRACE
    spv_demuxer_module_t *demuxer = NULL;

    spv_core_module_t *module = cycle->modules[index]->ctx;

    for (spv_int_t i = 0; cycle->modules[i]; i++) {
        if (cycle->modules[i]->type != SPV_DEMUXER_MODULE) {
            continue;
        }

        demuxer = cycle->modules[i]->ctx;
        if (strcmp(demuxer->name, "demuxer_lavf") == 0) {
            spv_log_debug(cycle->log, 0, "SELECT DEMUXER: %s", demuxer->name);
            break;
        }
    }

    module->priv_data = spv_calloc(demuxer->priv_data_size, cycle->log);
    

    return SPV_OK;
}

