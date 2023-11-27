/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:34:05 by lprieri       #+#    #+#                 */
/*   Updated: 2023/11/23 17:48:32 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* GNL */
char	*get_next_line(int fd);
void	ft_read(int fd, char **rem);
// void	ft_append(char *buffer, char **rem);
char	*ft_parse(char **rem, char **line);
char	*ft_get_remainder(char *rem);
char	*ft_get_nl_line(char **rem);

/* UTILS */
char	*ft_strdup(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
ssize_t	ft_strlen(char *str);
ssize_t	ft_checknl(char *str);
void	ft_free(char **str);

#endif