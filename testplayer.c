#include "includes/filler.h"

int		main()
{
	char	*str;
	get_next_line(0, &str);
	ft_printf("%s\n", str);
	free(str);
	get_next_line(0, &str);
	ft_printf("%s\n", str);
	free(str);
}
