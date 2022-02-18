#include "main.h"

static void freeARGV(char **argv)
{
    int i = 0;

    while (argv[i] != NULL)
        i++;
    while (i-- != 0)
    {
        free(argv[i]);
        argv[i] = NULL;
    }
    free(argv[0]);
    argv[0] = NULL;
}

int main(int argc, char **argv, char **env)
{
    char *cmd = NULL, cmd_read[512], **path = NULL, *pathCD = NULL;
    int ret2 = 0, i = 1, exit = 1, error = 0, j = 1;
    pid_t pid;

    path = pathAssembler(env);
    write(1, "New BunnySH opened\n", 20);
    if (argc >= 2)
    {
        std_strcpy(cmd_read, argv[1]);
        cmd = std_strmerge(path[0], "/", cmd_read);
    }
    while (exit)
    {
        if ((pid = fork()) == -1)
            return (-1);
        else if (pid == 0)
        {
            if (argc > 1)
                execve_shell(argv, env, path, i, j, cmd, cmd_read, pathCD);
            return (error);
        }
        else
        {
            waitpid(pid, NULL, 0);
            write(1, "&> ", 3);
            ret2 = read(1, cmd_read, 511);
            cmd_read[ret2 - 1] = '\0';
            if (cmd_read[0] != '/' && cmd_read[0] != '.' && std_strncmp(cmd_read, "cd", std_strlen("cd")) != 0)
                cmd = std_strmerge(path[0], "/", cmd_read);
            else
                cmd = std_strmerge("", "", cmd_read);
            argv = std_split(cmd, ' ');
            i = std_chara_founder(cmd, ' ');
            cmd[i] = '\0';
            i = 0;
            argc = 3;
            if (std_strncmp(cmd, "cd", std_strlen("cd")) == 0)
            {
                if (argv[1] != NULL)
                    path_cd(argv, pathCD, env);
                else
                    write(1, "Please specify directory.\n", 27);
            }
            if (std_strcmp(cmd_read, "exit") == 0)
                exit = 0;
        }
    }
    freeARGV(argv);
    freeARGV(path);
    free(cmd);
    cmd = NULL;
    free(pathCD);
    pathCD = NULL;
    write(1, "Bye-bye BunnySH !\n", 18);
    return (EXIT_SUCCESS);
}
