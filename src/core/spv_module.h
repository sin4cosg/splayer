/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_MODULE_H
#define SPV_MODULE_H


#include <spv_config.h>
#include <spv_core.h>


struct spv_module_s {
    spv_uint_t type;
    void *ctx;
    char *name;
    spv_int_t (*init_module)(spv_cycle_t *cycle, spv_uint_t index);
};


typedef struct {
    char *name;
    void *public_data;
    void *priv_data;
    void *delegate;
} spv_core_module_t;


spv_int_t spv_cycle_modules(spv_cycle_t *cycle);
spv_int_t spv_init_modules(spv_cycle_t *cycle);


extern spv_uint_t spv_max_modules;
extern spv_module_t *spv_modules[];


#endif  // SPV_MODULE_H
