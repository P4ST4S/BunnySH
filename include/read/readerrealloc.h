#ifndef __REREALLOC_H__
#define __REREALLOC_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "realloc.h"

char *std_read_realloc(const int fd, size_t *len);

#endif /* __REREALLOC_H__ */