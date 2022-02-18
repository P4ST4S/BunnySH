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
