#include "test.h"

int		*ft_test(int *tab, int *to_add, int tablen, int to_addlen)
{
	int *new;

	ft_simple_printf("tabfsjoin\n");
	if (!(new = (int*)ft_memalloc(sizeof(int) * (tablen + to_addlen))))
		return (NULL);
	ft_simple_printf("after new malloc\n");
	ft_tabcpy(tab, new, tablen);
	ft_simple_printf("after cpy tab in new\n");
	ft_tabcpy(to_add, new + tablen, to_addlen);
	ft_simple_printf("after cpy to_add in new\n");
	//free(to_add);
	ft_simple_printf("free to_add\n");
	return (new);
}

int main()
{
	int *tab;
	int value;
	int tablen;
	int i;

	tablen = 4;
	if (!(tab = (int*)ft_memalloc(sizeof(int) * tablen)))
		return (0);
	i = -1;
	while (++i < tablen)
		tab[i] = 10;
	value = 5;
	ft_test(tab, &value, tablen, 1);
	ft_simple_printf("after tabjsjoin\n");
	return (1);
}
