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
