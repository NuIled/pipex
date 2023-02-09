/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:57:14 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/09 03:26:10 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H




# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

size_t  ft_strlen(const char *s);
void	parentprocess(char **envp, char *filename, char *cmd);
char    **ft_split(char const *s, char c);
int     t_strncmp(const char *str1, const char *str2, size_t num);
int     ft_strchr(char *s, char c);
size_t  ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void    firstchiled(char **envp, char *filename, char *cmd);
char    *checkpath(char **envp);
void    ft_bzero(void *s, size_t n);
char    **checkcmd(char *cmd, char **envp);

#endif