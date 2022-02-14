#include "strlen.h"

size_t std_strlen(const char *str)
{
    int lenghtCaracter;

    lenghtCaracter = 0;
    while (str[lenghtCaracter] != '\0')
        lenghtCaracter++;
    return (lenghtCaracter);
}
