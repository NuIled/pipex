/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:14 by aoutifra          #+#    #+#             */
/*   Updated: 2023/01/22 08:18:18 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"
struct pipex {
    char *string;
    char **path;
    char **args;
    char *cmd;
}pipex;
char	**ft_split(char const *s, char c);
void firstchiled(char **envp, char **fdd,char **av );
void secchiled(char **envp, char **fd,char **av);
void *checkpath(char **envp);
char *checkcmd(char *cmd);