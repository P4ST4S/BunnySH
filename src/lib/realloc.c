/**
 * @ Author: Antoine ROSPARS
 * @ Create Time: 2022-02-19 17:07:57
 * @ Modified by: Antoine ROSPARS
 * @ Modified time: 2022-02-19 17:11:13
 * @ Copyright: © Antoine ROSPARS - All Rights Reserved.
 */

#include "realloc.h"

void *std_realloc(void *ptr, size_t new_size)
{
    unsigned int old_size;
    void *new_ptr;

    if (ptr == NULL)
        return (malloc(new_size));
    old_size = malloc_usable_size(ptr);
    if (new_size <= old_size)
        return (ptr);
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (malloc(new_size));
    std_memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return (new_ptr);
}
