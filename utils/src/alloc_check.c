#include "../../utils/inc/libft.h"

int	alloc_check(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("An error as occurred during a dynamic allocation\n", 2);
		return(1);
	}
	return (0);
}