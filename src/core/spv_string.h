/*
 * Copyright (C) SUMMER
 */


#ifndef SPV_STRING_H
#define SPV_STRING_H


#include <spv_config.h>
#include <spv_core.h>


#define spv_snprintf                    snprintf
#define spv_vsnprintf                   vsnprintf
#define spv_memzero(buf, size)          memset(buf, 0, size)
#define spv_memcpy(dst, src, size)      memcpy(dst, src, size)



#endif  // SPV_STRING_H
