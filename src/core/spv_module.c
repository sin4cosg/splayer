/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


spv_int_t
spv_cycle_modules(spv_cycle_t *cycle)
{
    cycle->modules = spv_calloc(sizeof(spv_module_t *) * (spv_max_modules + 1), cycle->log);
    if (cycle->modules == NULL) {
        return SPV_ERROR;
    }

    spv_memcpy(cycle->modules, spv_modules, sizeof(spv_module_t *) * spv_max_modules);

    cycle->modules_n = spv_max_modules;

    return SPV_OK;
}


spv_int_t
spv_init_modules(spv_cycle_t *cycle)
{
    for (spv_int_t i = 0; cycle->modules[i]; i++) {
        if (cycle->modules[i]->init_module) {
            cycle->modules[i]->init_module(cycle, i);
        }
    }

    return SPV_OK;
}
