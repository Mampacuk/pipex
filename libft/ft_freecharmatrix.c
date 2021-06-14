#include "libft.h"

void	ft_freecharmatrix(char **matrix)
{
	int	i;

	i = ft_charmatrixlen(matrix) - 1;
	while (i >= 0)
		free(matrix[i--]);
}
