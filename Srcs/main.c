/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:28:52 by ebellon           #+#    #+#             */
/*   Updated: 2021/10/01 16:15:07 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

void	ft_push_big(t_stack **a, t_stack **b, t_data *data)
{
	char	*opti_instr;

	data->nb_group = root(data->size) / 1.6;
	data->size_group = data->size / data->nb_group;
	data->i_group = 0;
	while (ft_stacksize(*b) < data->size)
	{
		push_b_group(data, a, b);
		data->i_group++;
	}
	data->i_group = data->size - (data->nb_group * data->size_group);
	while (data->i_group <= data->size)
	{
		push_a_group(data, a, b, ft_stacksize(*a));
		data->i_group += data->size_group;
	}
	opti_instr = opti_instructions(data->instructions);
	printf("%s", opti_instr);
	free(opti_instr);
}

void	ft_push_swap(int ac, t_stack **a, t_stack **b, t_data *data)
{
	if (ac > 5)
		ft_push_big(a, b, data);
	else if (ac > 3)
	{
		push_5(data, a, b);
		printf("%s", data->instructions);
		free(data->instructions);
	}
	else if (ac == 3)
	{
		push_3(data, a, 0);
		printf("%s", data->instructions);
		free(data->instructions);
	}
	else
	{
		sa_sb(*a, "sa\n", data);
		printf("%s", data->instructions);
		free(data->instructions);
	}
}

int	init_stack_with_string(char **av, t_data *data, t_stack **a)
{
	int	ac;
	int	i;

	i = 0;
	ac = 0;
	if (!av || !av[1])
	{
		free(data);
		exit(0);
	}
	while (av[ac])
		ac++;
	data->sort_tab = init_sort_tab(ac, av, 1, data);
	*a = init_stack(ac, av);
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	return (ac);
}

int	init_stack_with_args(char **av, t_data *data, t_stack **a, int ac)
{
	data->sort_tab = init_sort_tab(ac, av, 0, data);
	*a = init_stack(ac, av);
	return (ac);
}

int	main(int ac1, char **av1)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;
	int		ac;

	if (ac1 < 2 || !av1[1][0])
		return (0);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	data->instructions = NULL;
	if (ac1 == 2 && ft_chech_sing_arg(av1[1], data))
		ac = init_stack_with_string(ft_split(av1[1], ' '), data, &a);
	else
		ac = init_stack_with_args(av1 + 1, data, &a, ac1 - 1);
	if (a == NULL)
		return (1);
	b = NULL;
	data->size = ac;
	ft_push_swap(ac, &a, &b, data);
	ft_free_stack(a);
	free(data->sort_tab);
	free(data);
	return (0);
}
