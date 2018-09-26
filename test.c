#include "test.h"

int		ft_stack_sort(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_addbackstack(t_stack *stack, int value)
{
	t_stack *new;

	if (!(new = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (0);
	new = stack;
	while (new->next)
		new = new->next;
	new->value = value;
	new->next = stack;
	return (1);
}

void 	ft_print(t_stack *stack)
{
	ft_simple_printf("STACK :\n");
	while (stack->next)
	{
		ft_simple_printf("%d\t", stack->value);
		stack = stack->next;
	}
}

int 	main(int argc, char **argv)
{
	int i;
	t_stack *stack;
	t_stack *begin;

	i = 0;
	if (argc > 1)
	{
		if (!(stack = (t_stack*)ft_memalloc(sizeof(t_stack))))
			return (0);
		ft_simple_printf("argc : '%d'\n", argc);
		while (++i < argc)
		{
			ft_simple_printf("coucou1\n");
			ft_simple_printf("argv[%d] : '%s' : '%d'\n", i, argv[i], ft_atoi(argv[i]));
			if (i == 1)
				stack->value = ft_atoi(argv[i]);
			else
				ft_addbackstack(stack, ft_atoi(argv[i]));
			ft_simple_printf("value : '%d'\n", stack->value);
			stack->next = NULL;
			if (i == 1)
				begin = stack;
			ft_simple_printf("coucou2\n");
			stack = stack->next;
			ft_simple_printf("coucou3\n");
		}
		ft_simple_printf("coucou4\n");
		ft_print(begin);
		if (!ft_stack_sort(begin))
			ft_simple_printf("KOOOOO\n");
		else
			ft_simple_printf("OK GOOOOD\n");
	}
	return (0);
}
