/*
 * Copyright (C) SUMMER
 */


#include <spv_config.h>
#include <spv_core.h>


void *
spv_alloc(size_t size, spv_log_t *log)
{
    void *p;

    p = malloc(size);
    if (p == NULL) {
        spv_log_error(log, 0, "malloc(%zu) failed", size);
    }

    spv_log_debug(log, 0, "malloc: %p:%zu", p, size);

    return p;
}


void *
spv_calloc(size_t size, spv_log_t *log)
{
    void *p;

    p = spv_alloc(size, log);
    if (p) {
        spv_memzero(p, size);
    }

    return p;
}
