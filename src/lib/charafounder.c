#include "charafounder.h"

int std_chara_founder(const char *str, char c)
{
    int count = 0;

    while (str[count] != '\0')
    {
        if (str[count] == c)
            return (count);
        count++;
    }
    return (count);
}