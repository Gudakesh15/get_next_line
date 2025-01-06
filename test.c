//#include "get_next_line.h"
//trying to read from a file, 3 chars at a time

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

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

char    *get_next_line(int fd)
{
    int bytes_read;
    char    *cup_buffer;

    cup_buffer = ft_calloc(3 + 1, sizeof(char));
    if (!cup_buffer)
        return (NULL);
    bytes_read = read(fd, cup_buffer, 3);
    if (bytes_read <= 0)
        return (NULL);
    return (cup_buffer);
}

int main(void)
{
    int fd;
    char    *next_line;
    int count;

    count = 0;
    fd = open("example.txt", O_RDONLY);
    while (1)
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            break;
        count++;
        printf("[%d]: %s\n", count, next_line);
        next_line = NULL;
    }
    close(fd);
    return 0;


}