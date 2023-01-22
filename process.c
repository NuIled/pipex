/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:50:09 by aoutifra          #+#    #+#             */
/*   Updated: 2023/01/22 13:21:20 by aoutifra         ###   ########.fr       */
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
void ft_freealll(char ** arg)
{

}
void firstchiled(char **envp, char **fdd ,char *cmd)
{
	checkcmd (cmd,envp);
	int	filed = open(*fdd, O_RDONLY);
    dup2(filed,0);
    close(filed);
    if (execve(pipex.cmd, pipex.args, envp)==-1)
        {
            perror(ERR_CMD);
			exit(1);
        }
	execve(pipex.cmd, pipex.args, envp);
}
void secchiled(char **envp, char **fd,char **av)
{
   	checkcmd (av[3],envp);	 
    // checkcmd (&av);int fd=open(av[4],O_TRUNC | O_CREAT | O_RDWR, 0000644);
    int	filed = open(*fd,O_TRUNC | O_CREAT | O_RDWR, 0000644);
    dup2(filed,1);
    close(filed);
	if (execve(pipex.cmd, pipex.args, envp) == -1)
        {
            perror(ERR_CMD);
			exit(1);
        }
	execve(pipex.cmd, pipex.args, envp);
}