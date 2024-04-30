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
