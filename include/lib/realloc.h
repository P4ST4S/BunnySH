#ifndef __REALLOC_H__
#define __REALLOC_H__

#include <stdlib.h>
#include <malloc.h>

#include "memcpy.h"

void *std_realloc(void *ptr, size_t new_size);

#endif /* __REALLOC_H__ */