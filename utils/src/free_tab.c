
#include "../../utils/inc/libft.h"

void	free_tab(void **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
			i++;
		while (i >= 0)
			free(ptr[i--]);
		free(ptr);
		ptr = NULL;
	}
}
