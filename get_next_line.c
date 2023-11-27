/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:31:36 by lprieri       #+#    #+#                 */
/*   Updated: 2023/11/23 17:49:08 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("test1.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		ft_free(&str);
// 		str = get_next_line(fd);
// 	}
// 	ft_free(&str);
// 	close(fd);
// }

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		ft_free (&rem);
		return (NULL);
	}
	line = NULL;
	if (rem && ft_checknl(rem) >= 0)
		return (ft_parse(&rem, &line));
	ft_read(fd, &rem);
	if (rem && ft_checknl(rem) >= 0)
		return (ft_parse(&rem, &line));
	else if (rem && rem[0] == '\0')
	{
		ft_free(&rem);
		return (NULL);
	}
	else
	{
		line = ft_strdup(rem);
		ft_free(&rem);
		return (line);
	}
}

void	ft_read(int fd, char **rem)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	buffer[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0 && ft_checknl(buffer) < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_free(rem);
			ft_free(&buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*rem, buffer);
		ft_free(rem);
		*rem = ft_strdup(temp);
		ft_free(&temp);
	}
	ft_free(&buffer);
}

// void	ft_append(char *buffer, char **rem)
// {
// 	char	*temp;

// 	temp = ft_strjoin(*rem, buffer);
// 	ft_free(rem);
// 	*rem = ft_strdup(temp);
// 	ft_free(&temp);
// }

char	*ft_parse(char **rem, char **line)
{
	char	*temp;

	temp = ft_get_remainder(*rem);
	*line = ft_get_nl_line(rem);
	ft_free(rem);
	*rem = ft_strdup(temp);
	ft_free(&temp);
	return (*line);
}

char	*ft_get_remainder(char *rem)
{
	char	*new_rem;
	ssize_t	nl_index;
	ssize_t	rem_len;
	ssize_t	i;

	nl_index = ft_checknl(rem);
	rem_len = ft_strlen(rem);
	new_rem = malloc (rem_len - nl_index + 1);
	if (!new_rem)
		return (NULL);
	i = 0;
	while (rem && rem[i] && i < (rem_len - nl_index))
	{
		new_rem[i] = rem[nl_index + 1 + i];
		i++;
	}
	new_rem[i] = '\0';
	return (new_rem);
}

char	*ft_get_nl_line(char **rem)
{
	char	*line;
	ssize_t	line_len;
	ssize_t	i;

	line_len = ft_checknl(*rem);
	if (line_len < 0 && !(*rem))
		return (NULL);
	line = malloc(line_len + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (*rem && (*rem)[i] && i < line_len)
	{
		line[i] = (*rem)[i];
		i++;
	}
	if (*rem && (*rem)[i] && (*rem)[i] == '\n')
	{
		line[i] = (*rem)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
