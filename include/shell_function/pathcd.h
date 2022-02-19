/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:48
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#ifndef __PCD_H__
#define __PCD_H__

#include <stdlib.h>

#include "strmerge.h"
#include "strcmp.h"
#include "envfounder.h"

void path_cd(char **argv, char *pathCD, char **env);

#endif /* __PCD_H__ */