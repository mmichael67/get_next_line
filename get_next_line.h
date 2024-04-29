/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:44:15 by mmansuri          #+#    #+#             */
/*   Updated: 2024/04/30 00:01:14 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_free_null(char *buffer, char *temp);
size_t	ft_slen(const char *str);
char	*ft_str_nline(const char *s, int i1);
void	*ft_calloc(size_t totaln);
char	*ft_str_jfone(char *str1, char *str2);
#endif
