/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:50:09 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/06 13:32:39 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

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

void	firstchiled(char **envp, char *filename, char *cmd)
{
	int		fd;
	char	**command;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(ERR_INFILE);
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);
	close(fd);
	command = checkcmd (cmd, envp);
	if (execve(*command, command, envp) == -1)
	{
		perror(ERR_CMD);
		exit(1);
	}
}

void	parentprocess(char **envp, char *filename, char *cmd)
{
	int		fd;
	char	**command;

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0777);
	if (fd == -1)
	{
		perror(ERR_OUTFILE);
		exit(EXIT_FAILURE);
	}
	dup2(fd, 1);
	close(fd);
	command = checkcmd (cmd, envp);
	
	if (execve(*command, command, envp) == -1)
	{
		perror(ERR_CMD);
		exit(1);
	}
}