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