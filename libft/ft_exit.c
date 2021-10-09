#include "libft.h"

int	ft_exit(const char *msg, int code)
{
	ft_putstr_fd(msg, 2);
	exit(code);
}
