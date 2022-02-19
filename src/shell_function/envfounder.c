/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:10:27
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "envfounder.h"

int envFounder(char **env, char *search, int mode, char *cd)
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
            else if (mode == 3)
            {
                if (cd[std_strlen(cd) - 1] == '/')
                    cd[std_strlen(cd) - 1] = '\0';
                env[i] = std_strmerge(env[i], "/", cd);
            }
            else if (mode == 4)
            {
                j = std_strlen(env[i]);
                while (env[i][j] != '/')
                    j--;
                env[i][j] = '\0';
            }
            return (i);
        }
        i++;
    }
    write(1, "Environement not found\n", 24);
    return (i);
}
