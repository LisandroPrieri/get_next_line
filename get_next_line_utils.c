/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:37:06 by lprieri       #+#    #+#                 */
/*   Updated: 2024/02/02 18:26:47 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*gnl_strdup(char const *str)
// {
// 	char	*new;
// 	ssize_t	len;
// 	ssize_t	i;

// 	len = gnl_strlen((char *) str);
// 	new = malloc (len + 1);
// 	if (!new)
// 		return (gnl_free((char **) &str));
// 	i = 0;
// 	while (str && str[i] && i < len)
// 	{
// 		new[i] = str[i];
// 		i++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	ssize_t	len_s1;
	ssize_t	len_s2;
	ssize_t	i;

	len_s1 = gnl_strlen((char *) s1);
	len_s2 = gnl_strlen((char *) s2);
	str = malloc (len_s1 + len_s2 + 1);
	if (!str)
		return (gnl_free(&str), NULL);
	i = 0;
	while (s1 && s1[i] && i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	if (s1)
		gnl_free((char **) &s1);
	i = 0;
	while (s2 && s2[i] && i < len_s2)
	{
		str[len_s1 + i] = s2[i];
		i++;
	}
	str[len_s1 + len_s2] = '\0';
	return (str);
}

ssize_t	gnl_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

ssize_t	gnl_checknl(char *str)
{
	ssize_t	i;

	if (str == NULL || str[0] == '\0')
		return (-1);
	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_free(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free (*str);
		*str = NULL;
	}
	else
		*str = NULL;
	return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	s_len = gnl_strlen((char *) s);
	if (start > s_len)
	{
		start = s_len;
		len = 0;
	}
	if (len + start > s_len)
		len = s_len - start;
	str = (char *) malloc(len + 1);
	if (!str)
		return (gnl_free((char **) &s));
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
