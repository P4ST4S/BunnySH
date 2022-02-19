/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:10:29
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "dollarremp.h"

char **dollarRemplacement(char **argv, char **env)
{
    int index = dollarParse(argv);

    if (index != 0)
        argv[index] = pathFounder(env, &argv[index][1]);
    if (argv[index] == NULL)
    {
        argv[index] = NULL;
        argv[index][0] = '\0';
    }
    return (argv);
}