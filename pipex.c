/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/01/22 09:02:02 by aoutifra         ###   ########.fr       */
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
	while (src[j])
		s[i++] = src[j++];
	s[i] = 0;
	return (s);
}
void *checkpath(char **envp)
{
	while (**envp != 'P')
		envp++;
	pipex.path = envp;
	return 0;
}
char *checkcmd(char *cmd)
{	
	pipex.args = ft_split(cmd ,' ');
	char** path;
	path = ft_split(*pipex.path+5,':');
	while (*path)
	{
		*path=joing(*path, "/");
		pipex.cmd = joing (*path, *pipex.args);
		// printf("\n-----%s------\n",*pipex.cmd);
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
	checkpath(envp);
	// if (checkpath(envp)==0)
	// 	{
	// 		perror(ERR_INPUT);
	// 		exit(1);
	// 	}
	checkcmd (av[2]);
	checkcmd (av[3]);	    
	  int pipefd[2];
  //  create a pipe
    pipe(pipefd);
    pid_t pid = fork();
    if (pid == 0) {
       // child process//
        close(pipefd[0]); // close the read end
        dup2(pipefd[1], 1); // redirect stdout to write end of pipe
       firstchiled(envp,&av[1],0);
    } else {
        // parent process
        close(pipefd[1]); // close the write end
        dup2(pipefd[0], 0); // redirect stdin to read end of pipe
        secchiled(envp,&av[4],0);
        // execlp("grep", "grep", "example", NULL);
    }
	return (0);
}
/* take care of non ex files 
 take care of space tab newline cmd  strjoing take care of it
 free varyables
 take care of the path /usr/bin and non exist envp
 take care of fd and ac */