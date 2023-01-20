#include "pipex.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = strlen(s);
	if (s_len <= start)
		start = s_len;
	if (s_len - start < len)
		len = s_len - start;
	sub = calloc(len + 1, sizeof(char));
	if (sub && len)
		memmove(sub, s + start, len);
	return (sub);
}
static int	my_spliter(char **ret, char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	while (s[0])
	{
		i = 0;
		while (s[i] && (s[i] != c))
			i++;
		if (ret)
			ret[count] = ft_substr(s, 0, i);
		if (ret && ret[count] == NULL)
			return (-1);
		count++;
		while (s[i] && (s[i] == c))
			i++;
		s = s + i;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;

	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	if (!*s)
		return (calloc(1, sizeof(char *)));
	ret = calloc(my_spliter(0, s, c) + 1, sizeof(char *));
	if (my_spliter(ret, s, c) < 0)
	{
		i = 0;
		while (ret[i])
			free(ret[i++]);
		free(ret);
		return (NULL);
	}
	return (ret);
}
