/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:51
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#ifndef __ESHELL_H__
#define __ESHELL_H__

#include <stdlib.h>

#include "strncmp.h"
#include "strmerge.h"
#include "strlen.h"
#include "split.h"
#include "dollarremp.h"
#include "charafounder.h"

void execve_shell(char **argv, char **env, char **path, int i, int j, char *cmd, char *cmd_read, char *pathCD);

#endif /* __ESHELL_H__ */