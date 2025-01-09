/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaviral <aaviral@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:41:27 by aaviral           #+#    #+#             */
/*   Updated: 2025/01/09 20:26:48 by aaviral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *append_buffer(char *basin_buffer, char *cup_buffer)
{
    char    *temp;

    temp = ft_strjoin(basin_buffer, cup_buffer);
    if (basin_buffer)
        free (basin_buffer);
    return (temp);
}

static char    *read_from_file(char *basin_buffer, int fd)
{
    int bytes_read;
    char    *cup_buffer;
    
    cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!cup_buffer)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (free(cup_buffer), NULL);
        cup_buffer[bytes_read] = '\0';
        basin_buffer = append_buffer(basin_buffer, cup_buffer);
        if (ft_strchr(basin_buffer, '\n'))
            break;
    }  
    free(cup_buffer);
    return (basin_buffer);
}

char    *extract_line(char *basin_buffer)
{
    char    *line_pos;
    char    *result;
    size_t line_len;

    if(!basin_buffer || !*basin_buffer)
        return (NULL);

    line_pos = ft_strchr(basin_buffer, '\n');
    if (line_pos)
        line_len = line_pos - basin_buffer + 1;
    else
        line_len = ft_strlen(basin_buffer);
    result = malloc(line_len + 1);
    if (!result)
        return (NULL);
    ft_memcpy(result, basin_buffer, line_len);
    result[line_len] = '\0';
    return (result);
}

char    *obtain_remaining(char *basin_buffer)
{
    char    *line_pos;
    char    *remaining;
    size_t  line_len;

    line_pos = ft_strchr(basin_buffer, '\n');
    if (!line_pos)
        return(free(basin_buffer), NULL);
    line_len = ft_strlen(line_pos + 1);
    remaining = malloc(line_len + 1);
    if (!remaining)
        return(free(basin_buffer), NULL);
    ft_memcpy(remaining, line_pos + 1, line_len);
    remaining[line_len] = '\0';
    free(basin_buffer);
    return (remaining);
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
