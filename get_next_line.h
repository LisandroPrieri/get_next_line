/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:34:05 by lprieri       #+#    #+#                 */
/*   Updated: 2024/02/02 18:45:10 by lprieri       ########   odam.nl         */
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

/* UTILS */
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_free(char **str);
char	*gnl_strjoin(char const *s1, char const *s2);
ssize_t	gnl_strlen(char *str);
ssize_t	gnl_checknl(char *str); 


#endif