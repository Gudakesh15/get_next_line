#include "get_next_line.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *p;
    unsigned char   value;

    p = (unsigned char *)s;
    value = (unsigned char)c;
    while (n > 0)
    {
        *p = value;
        p++;
        n--;
    }
    return (s);
}


void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}


void    *ft_calloc(size_t count, size_t size)
{
    void    *ptr;
    size_t  total_size;

    total_size = count * size;
    if (count != 0 && total_size/count != size)
        return (NULL);
    ptr = malloc(total_size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, total_size);
    return (ptr);
}