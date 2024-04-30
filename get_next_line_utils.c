#include "get_next_line.h"

size_t	ft_slen(const char *s)
{
	size_t	i1;

	i1 = 0;
	while (s[i1])
		++i1;
	return (i1);
}

char	*ft_str_nline(const char *s, int i1)
{
	while (s[++i1])
		if (s[i1] == '\n')
			return ((char *)&s[i1]);
	return (NULL);
}

void	*ft_calloc(size_t totaln)
{
	char	*ptr;

	ptr = malloc(totaln);
	if (!ptr)
		return (NULL);
	while (totaln--)
		ptr[totaln] = 0;
	return (ptr);
}

char	*ft_str_jfone(char *str1, char *str2)
{
	char	*result_str;
	int		ls1;
	int		ls2;
	int		it;

	if (!str1 || !str2)
		return (NULL);
	ls1 = ft_slen(str1);
	ls2 = ft_slen(str2);
	it = ls1 + ls2;
	result_str = (char *)ft_calloc((it + 1) * sizeof(char));
	if (!result_str)
		return (NULL);
	while ((ls2--) > 0)
		result_str[--it] = str2[ls2];
	while ((ls1--) > 0)
		result_str[--it] = str1[ls1];
	free(str1);
	return (result_str);
}
