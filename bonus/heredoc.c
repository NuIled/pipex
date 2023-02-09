/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:08:52 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/06 13:40:55 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t			i;
	unsigned char	*str0;
	unsigned char	*str3;

	str0 = (unsigned char *)(str1);
	str3 = (unsigned char *)(str2);
	i = 0;
	while ((str0[i] || str3[i]) && i < num)
	{
		if (str0[i] > str3[i])
			return (1);
		else if (str0[i] < str3[i])
			return (-1);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*sr;

	i = 0;
	sr = (char *)(s);
	while (n > i)
	{
		sr[i] = 0;
		i++;
	}
}

void	heredoker(char **av, int i)
{
	int		fd;
	char	*file;

	if (i == 2 || (i == 3 && access("tmp", R_OK) == 0))
	{
		file = av[1];
		if (i == 3)
			file = "tmp";
		fd = ft_open(file, 2);
		dup2(fd, 0);
		close (fd);
	}
}

char	*ft_join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 && s2)
	{
		res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (!res)
			return (0);
		i = -1;
		j = -1;
		while (s1[++i])
			res[i] = s1[i];
		while (s2[++j])
			res[i + j] = s2[j];
		res[i + j] = '\0';
		return (res);
	}
	return (0);
}

int	herdoc(char **av)
{
	int		fd;
	char	*s;
	char	*r;

	s = ft_strdup("");
		r = ft_join(av[2], "\n");
		fd = ft_open("tmp", 0);
	while (1)
	{
		s = get_next_line(0);
		if (0 == ft_strncmp(r, s, ft_strlen(s)))
			break ;
		write(fd, s, ft_strlen(s));
	}
	close(fd);
	free(s);
	return (1);
}
