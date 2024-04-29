/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:43:25 by mmansuri          #+#    #+#             */
/*   Updated: 2024/04/30 01:28:31 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *s_buff)
{
	char	*buff_tmp;
	int		er_i;

	er_i = 1;
	buff_tmp = (char *)ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_tmp)
		return (NULL);
	while (er_i != 0)
	{
		er_i = read(fd, buff_tmp, BUFFER_SIZE);
		if (er_i == -1)
			return (free(s_buff), free(buff_tmp), NULL);
		buff_tmp[er_i] = '\0';
		s_buff = ft_str_jfone(s_buff, buff_tmp);
		if (!s_buff || !*s_buff)
			return (free(s_buff), free(buff_tmp), NULL);
		if (ft_str_nline(s_buff, -1))
			break ;
	}
	return (free(buff_tmp), s_buff);
}

char	*write_line_buff(char *s_buff, char *first_l)
{
	char	*second_l;
	int		i;
	int		len;

	i = -1;
	while (s_buff[++i] != '\0' && s_buff[i] != '\n')
		first_l[i] = s_buff[i];
	if (ft_str_nline(s_buff, -1))
		first_l[i++] = '\n';
	first_l[i] = '\0';
	i = 0;
	len = ft_slen(first_l);
	if (!s_buff[len])
		return (free(s_buff), NULL);
	second_l = (char *)ft_calloc((ft_slen(s_buff) - len + 1) * sizeof(char));
	if (!second_l)
		return (NULL);
	while (s_buff[len])
		second_l[i++] = s_buff[len++];
	return (free(s_buff), second_l);
}

// char	*ft_free_null(char **s_buff, char *temp)
// {
// 	if (s_buff != temp)
// 		free(s_buff);
// 	free(temp);
// 	return (NULL);
// }

char	*get_next_line(int fd)
{
	static char	*s_buff;
	char		*first_l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_buff)
	{
		s_buff = (char *)ft_calloc(1 * sizeof(char));
		if (!s_buff)
			return (NULL);
	}
	s_buff = read_file(fd, s_buff);
	if (!s_buff)
		return (free(s_buff), NULL);
	first_l = (char *)ft_calloc((ft_slen(s_buff) + 1) * sizeof(char));
	if (!first_l)
		return (NULL);
	s_buff = write_line_buff(s_buff, first_l);
	return (first_l);
}

// int main()
// {
// 	int fd = open("test", O_RDONLY);
// 	char *s;
// 	int i;

// 	i = 1;
// 	s = get_next_line(fd);
// 	while (++i < 10) {
		// printf("%s\n", s);
		// free(s);
		// s = get_next_line(fd);
	// }
	// 	printf("%s\n", s);
	// free(s);
// }
//cc -Wall -Wextra -Werror 
//-D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.cß
