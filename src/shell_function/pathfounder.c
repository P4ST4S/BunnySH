/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:10:14
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "pathfounder.h"

char *pathFounder(char **env, char *search)
{
    char *path;
    int i = 0, j = 0, k = 0;

    path = malloc(std_strlen(env[envFounder(env, search, 0, NULL)]) - std_strlen(search) + 1);
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
    free(path);
    path = NULL;
    return (NULL);
}
