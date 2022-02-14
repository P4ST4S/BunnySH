#include "readerrealloc.h"

char *std_read_realloc(const int fd, size_t *len)
{
    char *buf;
    size_t len_char = 128;

    buf = malloc(len_char);
    if (!buf)
        return (NULL);

    *len = read(fd, buf, len_char);
    if ((int)*len == EOF)
    {
        free(buf);
        buf = NULL;
    }
    buf[*len - 1] = '\0';
    return (buf);
}