/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:21:51 by analbarr          #+#    #+#             */
/*   Updated: 2023/02/05 20:21:10 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *read_line)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(read_line, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(read_line);
			free(buffer);
			return (0);
		}
		buffer[read_bytes] = '\0';
		read_line = ft_strjoin(read_line, buffer);
	}
	free(buffer);
	return (read_line);
}

char	*ft_get_line(char *read_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!read_line[i])
		return (0);
	while (read_line[i] && read_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (read_line[i] && read_line[i] != '\n')
	{
		line[i] = read_line[i];
		i++;
	}
	if (read_line[i] == '\n')
	{
		line[i] = read_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean(char *read_line)
{
	int		i;
	int		j;
	char	*cln_line;

	i = 0;
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (!read_line[i])
	{
		free(read_line);
		return (0);
	}
	cln_line = (char *)malloc((sizeof(char)) * (ft_strlen(read_line) - i + 1));
	if (!cln_line)
		return (0);
	i++;
	j = 0;
	while (read_line[i])
		cln_line[j++] = read_line[i++];
	cln_line[j] = '\0';
	free(read_line);
	return (cln_line);
}

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_line = ft_read_file(fd, read_line);
	if (!read_line)
	{
		free(read_line);
		return (0);
	}
	line = ft_get_line(read_line);
	read_line = ft_clean(read_line);
	return (line);
}

/*int	main(void)
{
	int	fd;
	char	*str;
	int	i;

	fd = open("prueba", O_RDONLY);
	i = 0;
	while (i < 10)
	{
		str = get_next_line(fd);
		str = get_next_line(0);
		printf("line %d: %s", i, str);
		free(str);
		i++;
	}
	close(fd);
	system ("leaks a.out");
	return(0);
}*/
