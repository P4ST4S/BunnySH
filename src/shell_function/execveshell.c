#include "execveshell.h"

void execve_shell(char **argv, char **env, char **path, int i, int j, char *cmd, char *cmd_read, char *pathCD)
{
    argv = dollarRemplacement(argv, env);
    j = 1;
    if (std_strncmp(cmd, "cd", std_strlen("cd")) != 0)
    {
        while (execve(cmd, &argv[i], env) == -1 && path[j] != NULL)
        {
            cmd = std_strmerge(path[j++], "/", cmd_read);
            argv = std_split(cmd, ' ');
            argv = dollarRemplacement(argv, env);
            i = std_chara_founder(cmd, ' ');
            cmd[i] = 0;
            i = 0;
        }
    }
    free(cmd);
    cmd = NULL;
    free(pathCD);
    pathCD = NULL;
}