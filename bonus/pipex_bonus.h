/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:14 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/06 10:40:40 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct pipex
{
	char	*cmd;
	char	**args;
}t_pipex;

void	firstchiled(char **envp, char *cmd);
char	**ft_split(char const *s, char c);
char	**checkpath(char **envp);
char	**pathgeter(char **envp);
void	ft_bzero(void *s, size_t n);
int		ft_open(char *filename, int i);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	tmpchiled(char **envp, char *cmd, char **av);
void	pipexstart(char **av, char **envp, int i);
char	**cmdcheck(char *cmd, char **envp);
void	firstchile(int ac, char **av, char **envp, char *cmd);
void	closepipes(int pipefd[2]);
int		herdoc(char **av);
char	*ft_join(char *s1, char *s2);
void	heredoker(char **av, int i);
void	ft_free(char **s);
#endif