/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:31:36 by lprieri       #+#    #+#                 */
/*   Updated: 2024/01/28 16:50:15 by lisandro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_parse(char **rem, char **line, int nl_pos);
static char	*gnl_read(char **rem, char **line, int fd);

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	int		i;

// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("GNL CALL 0: %s", str);
// 	i = 1;
// 	while (i < 10)
// 	{
// 		gnl_free(&str);
// 		str = get_next_line(fd);
// 		printf("GNL CALL %i: %s", i, str);
// 		i++;
// 	}
// 	gnl_free(&str);
// 	str = get_next_line(fd);
// 	printf("\nGNL CALL 3: %s", str);
// 	close(fd);
// }

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (line = NULL, gnl_free (&rem));
	if (rem && gnl_checknl(rem) >= 0)
		return (gnl_parse(&rem, &line, gnl_checknl(rem)));
	gnl_read(&rem, &line, fd);
	if (line && *line)
		return (line);
	else if (rem && rem[0] == '\0')
		return (gnl_free(&rem));
	else
		return (rem);
}

static char	*gnl_read(char **rem, char **line, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		if (*rem)
			return (gnl_free(rem));
		return (NULL);
	}
	buffer[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0 && gnl_checknl(buffer) < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (*rem)
				gnl_free(rem);
			return (gnl_free(&buffer));
		}
		buffer[bytes_read] = '\0';
		*rem = gnl_strjoin(*rem, buffer);
	}
	return (gnl_free(&buffer), gnl_parse(rem, line, gnl_checknl(*rem)));
}

static char	*gnl_parse(char **rem, char **line, int nl_pos)
{
	char	*new_rem;

	if (!rem || !*rem)
		return (NULL);
	if (!rem || (*rem && nl_pos < 0))
	{
		nl_pos = gnl_strlen(*rem);
		if (nl_pos == 0)
			return (gnl_free(rem), *line = NULL);
	}
	*line = gnl_substr(*rem, 0, nl_pos + 1);
	if (!line || *line == NULL)
		return (gnl_free(rem));
	else if (!rem || (*rem && gnl_checknl(*rem) < 0))
		return (gnl_free(rem), *line);
	else
		new_rem = gnl_substr(*rem, nl_pos + 1, gnl_strlen(*rem) - nl_pos + 1);
	gnl_free(rem);
	if (new_rem == NULL)
		return (gnl_free(line));
	return (*rem = new_rem, *line);
}
