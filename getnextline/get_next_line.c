/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:36:15 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/04/21 20:09:32 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
	return (str);
}

char	*ft_split_gnl(char **ptr)
{
	size_t	size;
	char	*new_temp;
	char	*end;

	if (!(*ptr))
		return (NULL);
	if (ft_strchr(*ptr, '\n'))
	{
		size = ft_strchr(*ptr, '\n') - *ptr + 1;
		new_temp = ft_substr(*ptr, 0, size);
		end = ft_strdup(ft_strchr(*ptr, '\n') + 1);
		free(*ptr);
		*ptr = end;
	}
	else
	{
		new_temp = (ft_strdup(*ptr));
		free(*ptr);
		*ptr = NULL;
	}
	if (!new_temp)
		return (NULL);
	return (new_temp);
}

char	*ft_strjoin_gnl(char *temp, char *buff)
{
	char	*new_string;
	size_t	i;

	if (!temp)
		return (ft_strdup(buff));
	if (!buff[0])
		return (temp);
	i = ft_strlen(temp) + ft_strlen(buff);
	new_string = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, temp, i + 1);
	ft_strlcat(new_string, buff, i + 1);
	free(temp);
	temp = NULL;
	return (new_string);
}

char	*ft_read_join(int fd, char *temp)
{
	ssize_t		bytes_read;
	char		buff[BUFFER_SIZE + 1];

	if (temp)
	{
		if (ft_strchr(temp, '\n'))
			return (temp);
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buff[bytes_read] = '\0';
		if (!buff[0])
			return (temp);
		temp = ft_strjoin_gnl(temp, buff);
		if (ft_strchr(buff, '\n'))
			return (temp);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp = NULL;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	temp = ft_read_join(fd, temp);
	if (!temp)
		return (NULL);
	if (temp[0] == 0)
	{
		free(temp);
		return (NULL);
	}
	line = ft_split_gnl(&temp);
	return (line);
}
