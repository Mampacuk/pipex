#include "libft.h"

void	ft_exit(const char *msg, int code)
{
	if (msg)
		ft_putstr_fd((char *)msg, 2);
	else
		perror(NULL);
	exit(code);
}
