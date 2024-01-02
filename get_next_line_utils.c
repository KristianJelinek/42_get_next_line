/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:50:32 by k                 #+#    #+#             */
/*   Updated: 2024/01/02 11:17:45 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*rtn;
	size_t	len;

	len = ft_strlen(s) + 1;
	rtn = malloc(sizeof(char) * len);
	if (!rtn)
		return (0);
	rtn = ft_memcpy(rtn, s, len);
	return (rtn);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	lenght_s1;
	size_t	lenght_s2;
	size_t	total_s_lenght;
	char	*rtn;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	lenght_s1 = ft_strlen((char *)s1);
	lenght_s2 = ft_strlen(s2);
	total_s_lenght = lenght_s1 + lenght_s2 + 1;
	rtn = malloc(sizeof(char) * total_s_lenght);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, lenght_s1);
	ft_memmove(rtn + lenght_s1, s2, lenght_s2);
	rtn[total_s_lenght - 1] = '\0';
	return (rtn);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == (char)i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if ((size_t)ft_strlen(s) < len + (size_t)start)
		str = malloc(ft_strlen(s) + 1);
	else
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
