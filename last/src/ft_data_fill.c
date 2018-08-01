/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:17:03 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 11:17:10 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_init_list(t_stack *stack)
{
	stack->prev = NULL;
	stack->next = NULL;
	stack->value = 0;
}

t_data		*ft_data_fill(char **argv, int argc t_data *data)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	if (!data = (t_data)ft_memalloc(t_data*))
		return (NULL);
	if (!stack_a = (t_stack)ft_memalloc(t_stack*))
		return (NULL);
	ft_init_list(stack_a);
	if (!stack_a = ft_stack_fill(argv, argc, stack_a))
		return (NULL);
	ft_min_max(data, 1);
	ft_size(data, 1);
	data->size[0] = data->size[1];
	data->min[0] = data->min[1];
	data->max[0] = data->max[1];
	if (!stack_b = (t_stack)ft_memalloc(t_stack*))
		return (NULL);
	stack_b = NULL;
	ft_init_list(stack_b);
	ft_data_stack(data);
	return (data);
}

void		ft_addbackstack(t_stack *stack, int value)
{
	t_stack *tmp;
	t_stack	*new;

	if (!new = (t_stack)ft_memalloc(t_stack*))
		return ;
	new->value = value;
	new->next = NULL;
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
}

t_stack		*ft_stack_fill(char **argv, int argc, t_stack *stack_a)
{
	int		i;
	char	**tmp;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i]), ' ')
		{
			if (!tmp = ft_strsplit(argv[i], ' '))
				return (NULL);
			while (*tmp)
			{
				if (!ft_addbackstack(stack_a, ft_atoi(*tmp)))
					return (NULL);
				*tmp++;
			}
		}
		else
			if (!ft_addbackstack(stack_a, ft_atoi(argv[i])))
				return (NULL);
	}
	return (stack);
}

void		ft_size(t_data *data, int truc)
{
	t_data *tmp;

	tmp = data;
	ft_bzero(t_data->size, 3);
	while (tmp->next)
	{
		data->size[truc] += 1;
		tmp = tmp->next
	}
}

void		ft_min_max(t_data *data, int truc)
{
	t_data *tmp;

	tmp = (truc == 1) ? data->stack_a : data->stack_b;
	data->min[truc] = tmp->value;
	data->max[truc] = tmp->value;
	while (tmp->next)
	{
		data->min[truc] = (data->min[truc] < tmp->value) ? tmp->value :
		data->min[truc];
		data->max[truc] = (data->max[truc] > tmp->value) ? tmp->value :
		data->max[truc];
		tmp = tmp->next;
	}
}
