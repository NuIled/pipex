/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/01/20 10:51:15 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
char	*joing(char *dst ,char *src)
{
	int j =0;
	int i =0;
	char *s = malloc(strlen(dst)+strlen(src)+2);
	while (dst[j])
		s[i++] = dst[j++];
	j = 0;
	s[i]='/';
	i++;
	while (src[j])
		s[i++] = src[j++];
	s[i] = 0;
	return (s);
}
void *checkpath(char **envp)
{
	while (**envp!='P')
		envp++;
	pipex.path = envp;
	return 0;
}
char *checkcmd(char **cmd)
{	
	pipex.args = ft_split(*cmd ,' ');
	char** path;
	path = ft_split(*pipex.path+5,':');
	while (*path)
	{
		pipex.cmd = joing (*path, *pipex.args);
		if (access(pipex.cmd, F_OK) == 0)
				return(pipex.cmd);
		path++;
	}
	perror("CMD NOT FOUND");
	exit(1);
}

int	main(int ac , char *av[], char *envp[])
{
	checkpath(envp);
	checkcmd (&av[2]);
	int	fd = open(av[1], O_RDONLY);
	dup2 (fd, 0);
	close(fd);

	execve(pipex.cmd, pipex.args, envp);
	// printf("%s",cmd);
	return (0);
}