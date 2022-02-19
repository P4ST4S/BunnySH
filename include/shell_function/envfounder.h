/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:53
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#ifndef __EFOUND_H__
#define __EFOUND_H__

#include <unistd.h>

#include "strlen.h"
#include "strncmp.h"
#include "strmerge.h"

int envFounder(char **env, char *search, int mode, char *cd);

#endif /* __EFOUND_H__ */