#ifndef __EFOUND_H__
#define __EFOUND_H__

#include <unistd.h>

#include "strlen.h"
#include "strncmp.h"
#include "strmerge.h"

int envFounder(char **env, char *search, int mode, char *cd);

#endif /* __EFOUND_H__ */