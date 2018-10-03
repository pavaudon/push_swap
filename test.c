#include "test.h"

int main()
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line))
		ft_simple_printf("LINE : '%s'\n", line);
	return (1);
}
