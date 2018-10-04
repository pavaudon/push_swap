#include "test.h"

int		*ft_testtabcpy(int *tab, int *to_cpy, int len)
{
	int i;

	i = -1;
	while (++i < len)
		to_cpy[i] = tab[i];
	return (to_cpy);
}

int		*ft_testtabfsjoin(int *tab, int to_add, int tablen)
{
	int *new;
	int i;

	if (!(new = (int*)ft_memalloc(sizeof(int) * (tablen + 1))))
		return (NULL);
	ft_testtabcpy(tab, new, tablen);
	i = -1;
	new[tablen] = to_add;
	free(tab);
	return (new);
}


int main()
{
	int *tab;
	int tablen;
	int value;
	int i;

	value = 4;
	tablen = 5;
	if (!(tab = (int*)ft_memalloc(sizeof(int) * tablen)))
		return (0);
	i = -1;
	while (++i < tablen)
		tab[i] = 10;
	i = -1;
	ft_simple_printf("TAB BEFORE JOIN\n");
	while (++i < tablen)
		ft_simple_printf("%d\t", tab[i]);
	ft_simple_printf("\n");
	tab = ft_testtabfsjoin(tab, value, tablen);
	i = -1;
	ft_simple_printf("\nTAB AFTER JOIN\n");
	while (++i <= tablen)
		ft_simple_printf("%d\t", tab[i]);
	return (1);
}
