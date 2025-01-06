#include "get_next_line.h"

static char    *read_from_file(int fd)
{
    int bytes_read;
    char    *cup_buffer;
    static int  count = 1;

    printf("ft_calloc#[%d]---", count++);
    
    cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!cup_buffer)
        return (NULL);
    bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (free(cup_buffer), NULL);
    return (cup_buffer);
}

char    *get_next_line(int fd)
{
    static char    *basin_buffer;

    basin_buffer = read_from_file(fd);
    return (basin_buffer);
}