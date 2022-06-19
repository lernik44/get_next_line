/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:35:31 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/04/15 15:35:33 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize > dstlen)
	{
		i = 0;
		while (i < dstsize - dstlen - 1 && src[i])
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = 0;
		return (srclen + dstlen);
	}
	return (srclen + dstsize);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (srcsize);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*text;
	size_t	min_len;

	min_len = len;
	if (ft_strlen(s + start) < len)
		min_len = ft_strlen(s + start);
	if (ft_strlen(s) < start)
		min_len = 0;
	text = (char *)malloc(sizeof(char) * (min_len + 1));
	if (!text)
		return (NULL);
	ft_strlcpy(text, s + start, min_len + 1);
	return (text);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	while (*str)
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	if (c == 0)
		return (str++);
	else
		return (NULL);
}
