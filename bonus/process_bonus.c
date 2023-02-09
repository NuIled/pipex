/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:50:09 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/06 13:37:35 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

char	**pathgeter(char **envp)
{
	char	**path;

	if (envp)
	{
		while (ft_strncmp(*envp, "PATH", 4) != 0)
			envp++;
		path = envp;
		return (path);
	}
	return (NULL);
}

void	pipexstart(char **av, char **envp, int i)
{
	int		pipefd[2];
	pid_t	pid;

	heredoker(av, i);
	pipe (pipefd);
	pid = fork();
	if (pid == -1)
		perror("fork error");
	if (!pid)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		firstchiled(envp, av[i]);
	}
	else
	{
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		close(pipefd[0]);
	}
}

void	firstchiled(char **envp, char *cmd)
{
	char	**command;

	command = cmdcheck (cmd, envp);
	if (execve(*command, command, envp) == -1)
	{
		perror(ERR_CMD);
		exit(1);
	}
}
