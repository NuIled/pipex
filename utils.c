/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 09:25:42 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/06 11:12:00 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1 )
{
	char	*s;
	size_t	i;

	i = ft_strlen(s1) + 1;
	s = malloc(i);
	if (s == 0)
		return (NULL);
	ft_strlcpy (s, s1, i);
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen (src);
	if (n)
	{
		while (src[i] && i < n - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (lensrc);
}

int	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 && s2)
	{
		res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (!res)
			return (NULL);
		i = -1;
		j = -1;
		while (s1[++i])
			res[i] = s1[i];
		while (s2[++j])
			res[i + j] = s2[j];
		res[i + j] = '\0';
		return (res);
	}
	return (NULL);
}