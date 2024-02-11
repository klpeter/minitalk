/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:17:16 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/21 17:52:10 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <fcntl.h>
// #include <stdio.h>

//read it until the end of the string is reached or new line character is found
static char	*ft_read(int fd, char *buffer)
{
	char	*temp;
	int		lread;

	lread = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	while (ft_strchrgnl(buffer, '\n') == 0 && lread != 0)
	{
		lread = read(fd, temp, BUFFER_SIZE);
		temp[lread] = '\0';
		buffer = ft_strjoingnl(buffer, temp);
	}
	free(temp);
	return (buffer);
}

//looking for the new line and null terminator
static int	ft_lookforn(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	return (i);
}

//shifting my buffer's contain
static char	*ft_buffershift(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	j = 0;
	i = ft_lookforn(buffer);
	if (buffer[i] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlengnl(buffer) - i + 1));
	if (line == NULL)
		return (NULL);
	i++;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

//extracting the printable line from the buffer
static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = NULL;
	if (!buffer[i])
		return (NULL);
	i = ft_lookforn(buffer);
	if (buffer[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (buffer[i] == '\0')
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (buffer[j] != '\0' && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[102400];
	char		*line;

	if (read(fd, NULL, 0) == -1)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_buffershift(buffer[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
