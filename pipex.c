/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/01/22 13:50:41 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
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
void *checkpath(char **envp)
{
	while (ft_strncmp(*envp , "PATH",4) != 0)
		envp++;
		pipex.path=envp;
		// ft_free(envp);
		return pipex.path;
	return (0);
}
char *checkcmd(char *cmd, char **envp)
{	
	if (cmd[0] == '/')
		{
					pipex.args=ft_split(cmd,' ');
					// printf("\n---%s----\n",cmd);
					pipex.cmd = *pipex.args;
			if (access(pipex.cmd,0) == 0)
					return(pipex.cmd);
			else	
			free(cmd);
			perror(ERR_CMD);
			exit(1);
		}
	pipex.args = ft_split(cmd ,' ');
	char** path;
	path = ft_split(*pipex.path+5,':');
	while (*path)
	{
		*path = ft_strjoin(*path, "/");
		pipex.cmd = ft_strjoin (*path, *pipex.args);
		if (access(pipex.cmd,0) == 0)
				return(pipex.cmd);
		path++;
	}
	perror(ERR_CMD);
	exit(1);
}

int	main(int ac , char *av[], char *envp[])
{
	if (ac != 5){
		perror(ERR_INPUT);
		exit(1);
	}
	// int fd = open(av[2],O_RDONLY);
	// if (fd < 0)
	// 	{
	// 		perror(ERR_INFILE);
	// 		exit(1);
	// 	}
	checkpath(envp);
	  int pipefd[2];
  //  create a pipe
    pipe(pipefd);
    pid_t pid = fork();
    if (pid == 0) {
       // child process//
        close(pipefd[0]); // close the read end
        dup2(pipefd[1], 1); // redirect stdout to write end of pipe
       firstchiled(envp,&av[1],av[2]);
    } else {
        // parent process   
		waitpid(pid,0,0);
        close(pipefd[1]); // close the write end
        dup2(pipefd[0], 0); // redirect stdin to read end of pipe
        secchiled(envp,&av[4],av);
        // execlp("grep", "grep", "example", NULL);
    }
	return (0);
}
/* take care of non ex files 1
 take care of space tab newline cmd  strjoing take care of it1
 free varyables0
 take care of the path /usr/bin and non exist envp 1
 take care of fd and ac 0*/