#include "pathcd.h"

void path_cd(char **argv, char *pathCD, char **env)
{
    pathCD = std_strmerge(".", "/", argv[1]);
    if (chdir(pathCD) != 0)
        write(1, "Please specify correct directory.\n", 35);
    else
    {
        if (std_strcmp("..", argv[1]) != 0 && std_strcmp(".", argv[1]) != 0)
            envFounder(env, "PWD", 3, argv[1]);
        else if (std_strcmp("..", argv[1]) == 0)
            envFounder(env, "PWD", 4, NULL);
    }
}