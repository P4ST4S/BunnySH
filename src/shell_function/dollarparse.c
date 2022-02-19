/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:10:32
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "dollarparse.h"

int dollarParse(char **argv)
{
    int index = 0;

    while (argv[index] != NULL)
    {
        if (argv[index][0] == '$')
            return (true);
        (index)++;
    }
    return (0);
}
