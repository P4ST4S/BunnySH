/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:10:20
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "pathassembler.h"

char **pathAssembler(char **env)
{
    char **path, *pathNotSplit;

    pathNotSplit = pathFounder(env, "PATH");
    path = std_split(pathNotSplit, ':');
    free(pathNotSplit);
    pathNotSplit = NULL;
    return (path);
}
