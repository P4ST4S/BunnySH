#include "strcpy.h"

char *std_strcpy(char *dest,
                 const char *src)
{
    int count;

    count = 0;
    while (src[count] != '\0')
    {
        dest[count] = src[count];
        count++;
    }
    dest[count++] = '\0';
    return (dest);
}