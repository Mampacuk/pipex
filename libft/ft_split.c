#include "libft.h"

static int	ft_word_count(char *str, int d)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!str)
		return (words);
	while (str[i])
	{
		// dprintf(2, "on [%c]; next one is [%c], the check is (%d)\n", str[i], str[i + 1], !(d == str[i]) && (d == str[i + 1] || str[i + 1] == '\0'));
		if (!(d == str[i]) && (d == str[i + 1] || str[i + 1] == '\0')) 
			words++;
		i++;
	}
	return (words);
}

static char	*ft_word_beginning(char *str, int d)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(d == str[i]))
			return (str + i);
		i++;
	}
	return (NULL);
}

static char	*ft_word_ending(char *str, int d)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(d == str[i]) && (d == str[i + 1] || str[i + 1] == '\0'))
			return (str + i);
		i++;
	}
	return (NULL);
}

static void	ft_write_word(char ***mtx, char **str, int i, int d)
{
	int		j;
	char	*word_ending;
	char	*word_beginning;
	char	**result;

	result = *mtx;
	word_ending = ft_word_ending(*str, d);
	word_beginning = ft_word_beginning(*str, d);
	result[i] = ft_calloc(sizeof(char), word_ending
		- word_beginning + 2);
	j = 0;
	while (word_beginning + j <= word_ending)
	{
		result[i][j] = *(word_beginning + j);
		j++;
	}
	*str = word_ending + 1;
}

char	**ft_split(char *str, int d)
{
	char	**result;
	int		i;
	int		words;
	char	*temp;
	
	words = ft_word_count(str, d);
	result = ft_calloc(sizeof(char *), words + 1);
	if (!words || !result)
		return (NULL);
	temp = str;
	i = 0;
	while (i < words)
		ft_write_word(&result, &temp, i++, d);
	return (result);
}
