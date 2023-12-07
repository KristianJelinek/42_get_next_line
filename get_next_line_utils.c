/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:50:32 by k                 #+#    #+#             */
/*   Updated: 2023/12/07 16:09:34 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*dst;
	const char	*src;
	char		*rtn;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	*rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	dst = rtn;
	*src = s;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (rtn);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	char	*rtn;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	len1 = (s1) ? ft_strlen(s1) : 0;
	len2 = (s2) ? ft_strlen(s2) : 0;
	*rtn = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!rtn)
		return (NULL);
	*dst = rtn;
	if (s1)
	{
		while (*s1 != '\0')
			*dst++ = *s1++;
	}
	if (s2)
	{
		while (*s2 != '\0')
			*dst++ = *s2++;
	}
	*dst = '\0';
	return (rtn);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	return (*s == (char)c) ? (char *)s : NULL;
}

size_t	ft_strlen(const char *str)
{
	const char	*s = str;

	while (*s != '\0')
		s++;
	return (s - str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*dst;
	const char	*src;
	size_t		sub_len;
	char		*str;
	size_t		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len >= s_len - start)
	{
		sub_len = s_len - start;
	}
	else
	{
		sub_len = len;
	}
	*str = (char *)malloc(sub_len + 1);
	if (!str)
		*dst = str;
	*src = s + start;
	return (NULL);
	while (sub_len-- > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (str);
}
