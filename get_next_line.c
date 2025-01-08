#include "get_next_line.h"

static char    *read_from_file(char *basin_buffer, int fd)
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
    char    *line;

    if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!basin_buffer)
        basin_buffer = ft_calloc(1, sizeof(char));
    if (!ft_strchr(basin_buffer, '\n'))
        basin_buffer = read_from_file(basin_buffer, fd);
    if (!basin_buffer)
        return (free(basin_buffer), NULL);
    line = extract_line(basin_buffer);
    basin_buffer = obtain_remaining(basin_buffer);
    return (line);
}

/*


    while (*basin_buffer != '\n' || *basin_buffer != '\0' || *basin_buffer != EOF || fd != -1)
    {
        basin_buffer = read_from_file(fd);
        if (!basin_buffer)
            return (NULL);
    }
    return (basin_buffer);
}
*/