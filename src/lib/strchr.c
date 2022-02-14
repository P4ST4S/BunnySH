#include "strchr.h"

char *std_strchr(const char *s, int c)
{
    if (s == NULL)
    {
        return NULL;
    }
    if ((c > 255) || (c < 0))
    {
        return NULL;
    }
    int s_len;
    int i;
    s_len = std_strlen(s);
    for (i = 0; i < s_len; i++)
    {
        if ((char)c == s[i])
        {
            return ((char *)&s[i]);
        }
    }
    return NULL;
}