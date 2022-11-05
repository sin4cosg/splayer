/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


spv_uint_t spv_max_modules = 2;
spv_module_t *spv_modules[] = {
    &spv_demuxer_core_module,
    &spv_demuxer_lavf_module,
};
