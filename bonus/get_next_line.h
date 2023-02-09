/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:59:05 by aoutifra          #+#    #+#             */
/*   Updated: 2023/02/09 03:25:46 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include"pipex_bonus.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000

# endif



char	*ft_readline(int fd, char *str);
char	*ft_saver(char *s, int start);
char	*get_next_line(int fd);
char	*ft_getline(char *s, int i);
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_clear(char **stat);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif