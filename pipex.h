/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:14 by aoutifra          #+#    #+#             */
/*   Updated: 2023/01/22 13:21:09 by aoutifra         ###   ########.fr       */
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
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *str1, const char *str2, size_t num);
int	ft_strchr(char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void firstchiled(char **envp, char **fdd ,char *cmd);
void secchiled(char **envp, char **fd,char **av);
void *checkpath(char **envp);
void	ft_bzero(void *s, size_t n);
char *checkcmd(char *cmd, char **envp);
