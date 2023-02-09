/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/07 22:23:01 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	ret = NULL;
	free(ret);
}

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

char	*checkpath(char **envp)
{
	char	*path;

	while (ft_strncmp(*envp, "PATH", 4) != 0)
		envp++;
	path = *envp;
	return (path);
}

char	**checkcmd(char *cmd, char **envp)
{	
	char	**args;
	char	*path;
	char	*cmdd;
	char	**paths;

	args = ft_split(cmd, ' ');
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(*args, X_OK) == 0)
			return (args);
		perror(ERR_CMD);
		exit(1);
	}
	paths = ft_split((checkpath(envp) + 5), ':');
	cmdd = *args;
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		*args = ft_strjoin(path, cmdd);
		if (access(*args, X_OK) == 0)
			return (ft_free(paths), free(path), free(cmdd), args);
		paths++;
	}
	perror(ERR_CMD);
	exit(1);
}

int	main(int ac, char *av[], char *envp[])
{
	pid_t	pid;
	int		pipefd[2];

	if (ac != 5)
		exit(EXIT_FAILURE);
	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		firstchiled(envp, av[1], av[2]);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		parentprocess(envp, av[4], av[3]);
	}
	return (0);
}
