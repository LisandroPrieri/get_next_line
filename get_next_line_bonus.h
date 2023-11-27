/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/24 12:34:36 by lprieri       #+#    #+#                 */
/*   Updated: 2023/11/24 15:10:26 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* GNL */
char	*get_next_line(int fd);
char	*ft_parse(int fd, char **rem, char **line);
char	*ft_get_remainder(char *rem);
char	*ft_get_nl_line(char *rem);
void	ft_read(int fd, char **rem);

/* UTILS */
char	*ft_strjoin(char const *s1, char const *s2);
ssize_t	ft_checknl(char *str);
char	*ft_strdup(char const *str);
ssize_t	ft_strlen(char *str);
void	ft_free(int fd, char **arr);

#endif