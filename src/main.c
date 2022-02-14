#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#include "strmerge.h"
#include "strdup.h"
#include "strcpy.h"
#include "strcmp.h"
#include "strncmp.h"
#include "split.h"
#include "strchr.h"

static int envFounder(char **env, char *search, int mode)
{
    int i = 0, j = 0;

    while (env[i] != NULL)
    {
        if (std_strncmp(env[i], search, std_strlen(search)) == 0)
        {
            while (env[i][j] != '=')
                j++;
            j++;
            if (mode == 1)
            {
                write(1, &env[i][j], std_strlen(&env[i][j]));
                write(1, "\n", 1);
            }
            return (i);
        }
        i++;
    }
    write(1, "Environement not found\n", 24);
    return (i);
}

static char *pathFounder(char **env, char *search)
{
    char *path;
    int i = 0, j = 0, k = 0;

    path = malloc(std_strlen(env[envFounder(env, search, 0)]) - std_strlen(search) + 1);
    // puts("1");
    if (!path)
        return (NULL);
    while (env[i] != NULL)
    {
        if (std_strncmp(env[i], search, std_strlen(search)) == 0)
        {
            while (env[i][j] != '=')
                j++;
            j++;
            while (env[i][j] != '\0')
                path[k++] = env[i][j++];
            path[k] = '\0';
            return (path);
        }
        i++;
    }
    return (NULL);
}

static char **pathAssembler(char **env)
{
    char **path, *pathNotSplit;

    pathNotSplit = pathFounder(env, "PATH");
    path = std_split(pathNotSplit, ':');
    return (path);
}

static void freeARGV(char **argv)
{
    int i = 0;

    while (argv[i] != NULL)
        i++;
    while (i != 0)
    {
        free(argv[i]);
        argv[i] = NULL;
        i--;
    }
    free(argv[0]);
    argv[0] = NULL;
}

int main(int argc, char **argv, char **env)
{
    char *cmd = NULL, cmd_read[512], **path, *pathCD;
    int ret2, i = 1, exit = 1, error = 0, j = 1;
    pid_t pid, wstatus;

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
            if (argc >= 2)
            {
                j = 1;
                if (std_strncmp(cmd_read, "echo $", std_strlen("echo $")) != 0 && std_strncmp(cmd, "cd", std_strlen("cd")) != 0)
                {
                    while (execve(cmd, &argv[i], env) == -1 && path[j] != NULL)
                    {
                        cmd = std_strmerge(path[j++], "/", cmd_read);
                        argv = std_split(cmd, ' ');
                        i = std_chara_founder(cmd, ' ');
                        cmd[i] = 0;
                        i = 0;
                    }
                }
                else if (std_strncmp(cmd_read, "echo $", std_strlen("echo $")) == 0)
                    envFounder(env, &cmd_read[std_strlen("echo $")], 1);
                free(cmd);
                cmd = NULL;
            }
            return (error);
        }
        else
        {
            waitpid(pid, &wstatus, 0);
            if (WIFEXITED(wstatus))
                error = WEXITSTATUS(wstatus);
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
                {
                    pathCD = std_strmerge(".", "/", argv[1]);
                    if (chdir(pathCD) != 0)
                        write(1, "Please specify correct directory.\n", 35);
                }
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
    write(1, "Bye-bye BunnySH !\n", 18);
    return (EXIT_SUCCESS);
}
