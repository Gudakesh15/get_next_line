#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif


#include <stdio.h>    // For printf, NULL
#include <stdlib.h>   // For malloc, free
#include <unistd.h>   // For read, close
#include <fcntl.h>    // For open, O_RDONLY
#include <stddef.h>   // For size_t


char    *get_next_line(int fd);
void    *ft_memset(void *s, int c, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size);

#endif
