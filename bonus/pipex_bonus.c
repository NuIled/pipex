/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_bons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/01 20:15:38 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	ret = NULL;
	free(ret);
}

int	ft_open(char *filename, int i)
{
	int		file;

	file = 0;
	if (filename && i == 2)
		file = open(filename, O_RDONLY, 0000644);
	else
		file = open(filename, O_TRUNC | O_CREAT | O_RDWR, 0000777);
	if (file == -1)
	{
		perror (ERR_INFILE);
		exit (1);
	}
	return (file);
}

char	**cmdwithpath(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (access(*args, X_OK) == 0)
		return (args);
	free(args);
	perror(ERR_CMD);
	exit(EXIT_FAILURE);
}

char	**cmdcheck(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	char	**args;
	char	*cmdd;

	if (cmd[0] == '/' || cmd[0] == '.')
		return (args = cmdwithpath(cmd), args);
	path = *pathgeter(envp);
	paths = ft_split((path + 5), ':');
	args = ft_split(cmd, ' ');
	cmdd = *args;
	while (*paths)
	{
		path = ft_join(*paths, "/");
		*args = ft_join(path, cmdd);
		if (access(*args, X_OK) == 0)
			return (free(path), ft_free(paths), free(cmdd), args);
		paths++;
	}
	ft_free(paths);
	free(path);
	ft_free(args);
	free(cmdd);
	perror(ERR_CMD);
	exit(EXIT_FAILURE);
}

int	main(int ac, char *av[], char *envp[])
{
	int			i;
	int			fd;
		system("leaks pipex");
	if (ac < 5)
		exit (1);
	i = 1;
	if (ft_strncmp("here_doc", av[1], ft_strlen("here_doc")) == 0)
	{
		if (ac < 6)
			exit (1);
		herdoc(av);
		i = 2;
	}
	while (++i < ac - 2)
		pipexstart(av, envp, i);
	waitpid(0, NULL, -1);
	fd = ft_open(av[ac - 1], 1);
	dup2(fd, 1);
	close(fd);
	if (access("tmp", R_OK) == 0)
		unlink("tmp");
	firstchiled(envp, av[ac - 2]);
	return (0);
}
/* take care of non ex files 1
 take care of space tab newline cmd  strjoing take care of it1
 free varyables0
 take care of the path /usr/bin and non exist envp 1*/

//  all protection nedded 
