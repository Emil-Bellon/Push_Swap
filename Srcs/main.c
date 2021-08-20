/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:28:52 by ebellon           #+#    #+#             */
/*   Updated: 2021/08/20 19:12:07 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"
#include <limits.h>

int	ft_atoi_ps(const char *str, int *tab, char **av, int av_mal)
{
	int		i;
	long	nb;
	int		sign;
	int		err;

	sign = 1;
	i = 0;
	nb = 0;
	err = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		if (nb < 0 && sign == -1)
			err = 1;
		else if (nb < 0 && sign == 1)
			err = 1;
		i++;
	}
	if (i > 11 || i < (int)ft_strlen(str) || err == 1 || (nb > INT_MAX && sign == 1) || (nb > 2147483648 && sign == -1))
	{
		free(tab);
		i = 0;
		if (av_mal == 1)
		{
			while(av[i])
			{
				free(av[i]);
				i++;
			}
			free(av);
		}
		printf("Error : args should only be int input as digit\n");
		exit(1);
	}
	return ((int)nb * sign);
}


t_stack	*init_stack(int ac, char **av)
{
	t_stack	*fst;
	t_stack	*new;
	int		i;

	fst = NULL;
	i = 1;
	if (ac >= 2)
	{
		fst = ft_stacknew(ft_atoi(av[0]));
		while (i < ac)
		{
			if (ft_in_stack(fst, ft_atoi(av[i])) == 1)
			{
				ft_free_stack(fst);
				printf("Error\n-> There are duplicates\n");
				return (NULL);
			}
			new = ft_stacknew(ft_atoi(av[i]));
			ft_stackadd_back(&fst, new);
			i++;
		}
	}
	return (fst);
}

int	swap(int *tab, int j)
{
	int	swap;

	swap = tab[j];
	tab[j] = tab[j + 1];
	tab[j + 1] = swap;
	return (1);
}

int	*init_sort_tab(int ac, char **av, int av_mal)
{
	int	*tab;
	int	i;
	int	j;
	int	sort;

	j = 0;
	i = 0;
	tab = malloc(sizeof(int) * ac);
	while (j < ac)
		tab[i++] = ft_atoi_ps(av[j++], tab, av, av_mal);
	i = -1;
	sort = 0;
	while (++i < ac)
	{
		j = -1;
		while (++j < ac - i - 1)
		{
			if (tab[j] > tab[j + 1])
				sort = swap(tab, j);
		}
	}
	if (sort == 1)
		return (tab);
	free(tab);
	exit(0);
}

int	content_in_group(t_data *data, int content, int start)
{
	int	i;

	i = 0;
	while (start + i < data->size && i < data->size_group)
	{
		if (content == data->sort_tab[start + i])
			return (1);
		i++;
	}
	return (0);
}

void	push_b_group(t_data *data, t_stack **a, t_stack **b)
{
	while (ft_stacksize(*b) < data->size
		&& ft_stacksize(*b) < (data->i_group + 1) * data->size_group)
	{
		if (content_in_group(data, (*a)->content,
				data->i_group * data->size_group) == 1)
			pa_pb(a, b, "pb \n", data);
		else
			rra_rrb(a, "rra\n", data);
	}
}

int	rotate_b(int *rot, int size_group, t_stack **b, t_data *data)
{
	ra_rb(b, "rb \n", data);
	*rot += 1;
	if (*rot >= size_group)
		return (0);
	return (1);
}

int	rotate_inv_b(int *rot, t_stack **b, t_data *data)
{
	rra_rrb(b, "rrb\n", data);
	*rot -= 1;
	if (*rot <= 0)
		return (1);
	return (0);
}

void	push_a_group(t_data *data, t_stack **a, t_stack **b, int group)
{
	int	i;
	int	rot;
	int	dir_rot;
	int	size_group;

	i = data->size - group - 1;
	rot = 0;
	dir_rot = 1;
	size_group = data->size_group;
	while (ft_stacksize(*a) < data->i_group)
	{
		if (size_group == 0)
			size_group = data->size_group;
		if ((*b)->content == data->sort_tab[i])
		{
			pa_pb(b, a, "pa \n", data);
			i--;
			size_group--;
		}
		else if (dir_rot == 1)
			dir_rot = rotate_b(&rot, size_group, b, data);
		else if (dir_rot == 0)
			dir_rot = rotate_inv_b(&rot, b, data);
	}
}

void	search_dumb_instr(char *str, char *instructions, int offset, int i)
{
	int		j;
	int		count_inv;
	int		mem_i;

	j = 0;
	while (str[i])
	{
		count_inv = 0;
		mem_i = i;
		while (str[i] == 'r' && str[i + offset] == 'b')
		{
			i += 4;
			count_inv++;
		}
		if (str[i] != 'p')
			i += count_inv * 4;
		else
			i = mem_i;
		mem_i = 0;
		while (mem_i++ < 4)
			instructions[j++] = str[i++];
	}
	instructions[j] = 0;
}

char	*erase_spaces(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = ft_calloc(ft_strlen(str), sizeof(char));
	while (str[i])
	{
		if (str[i] != ' ')
		{
			ret[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (ret);
}

char	*opti_instructions(char *str)
{
	char	*instructions;

	instructions = ft_calloc(ft_strlen(str), sizeof(char));
	search_dumb_instr(str, instructions, 1, 0);
	free(str);
	str = ft_strdup(instructions);
	free(instructions);
	instructions = ft_calloc(ft_strlen(str), sizeof(char));
	search_dumb_instr(str, instructions, 2, 0);
	free(str);
	instructions = erase_spaces(instructions);
	return (instructions);
}

void	push_3_part2(t_data *data, t_stack **a, int offset)
{
	if ((*a)->content == data->sort_tab[1 + offset]
		&& (*a)->next->content == data->sort_tab[2 + offset]
		&& (*a)->next->next->content == data->sort_tab[0 + offset])
		rra_rrb(a, "rra\n", data);
	else if ((*a)->content == data->sort_tab[2 + offset]
		&& (*a)->next->content == data->sort_tab[1 + offset]
		&& (*a)->next->next->content == data->sort_tab[0 + offset])
	{
		sa_sb(*a, "sa\n", data);
		rra_rrb(a, "rra\n", data);
	}
	else if ((*a)->content == data->sort_tab[2 + offset]
		&& (*a)->next->content == data->sort_tab[0 + offset]
		&& (*a)->next->next->content == data->sort_tab[1 + offset])
		ra_rb(a, "ra\n", data);
}

void	push_3(t_data *data, t_stack **a, int offset)
{
	if ((*a)->content == data->sort_tab[0 + offset]
		&& (*a)->next->content == data->sort_tab[2 + offset]
		&& (*a)->next->next->content == data->sort_tab[1 + offset])
	{
		sa_sb(*a, "sa\n", data);
		ra_rb(a, "ra\n", data);
	}
	else if ((*a)->content == data->sort_tab[1 + offset]
		&& (*a)->next->content == data->sort_tab[0 + offset]
		&& (*a)->next->next->content == data->sort_tab[2 + offset])
		sa_sb(*a, "sa\n", data);
	else
		push_3_part2(data, a, offset);
}

void	push_5(t_data *data, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (ft_stacksize(*a) > 3)
	{
		if ((*a)->content == data->sort_tab[i])
		{
			pa_pb(a, b, "pb\n", data);
			i++;
		}
		else if ((*a)->next->content == data->sort_tab[i]
			|| (*a)->next->next->content == data->sort_tab[i])
			ra_rb(a, "ra\n", data);
		else
			rra_rrb(a, "rra\n", data);
	}
	if (ft_stacksize(*b) == 2)
	{
		push_3(data, a, 2);
		pa_pb(b, a, "pa\n", data);
	}
	else
		push_3(data, a, 1);
	pa_pb(b, a, "pa\n", data);
	
}

int	main(int ac1, char **av1)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;
	char	**av;
	int		ac;
	char	*opti_instr;
	int		i = 0;

	data = malloc(sizeof(t_data));
	data->instructions = NULL;
	if (ac1 < 2)
		return (printf("Error : need at list one string of argument or 2 arguments\n"));
	else if (ac1 == 2)
	{
		av = ft_split(av1[1], ' ');
		if (!av || !av[2])
		{
			free(av[0]);
			free(av);
			free(data);
			return (printf("Error : need more than 1 argument in string\n"));
		}
		ac = 0;
		while (av[ac])
			ac++;
		data->sort_tab = init_sort_tab(ac, av, 1);
		a = init_stack(ac, av);
		while(av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	else
	{
		av = av1 + 1;
		ac = ac1 - 1;
		data->sort_tab = init_sort_tab(ac, av, 0);
		a = init_stack(ac, av);
	}
	// for (int i = 0; i < ac; i++)
	// 	printf("%d\n", data->sort_tab[i]);
	if (a == NULL)
		return (1);
	b = NULL;
	data->size = ac;
	if (ac > 5)
	{
		data->nb_group = sqrt(data->size) / 1.6;
		data->size_group = data->size / data->nb_group;
		data->i_group = 0;
		while (ft_stacksize(b) < data->size)
		{
			push_b_group(data, &a, &b);
			data->i_group++;
		}
		data->i_group = data->size - (data->nb_group * data->size_group);
		while (data->i_group <= data->size)
		{
			push_a_group(data, &a, &b, ft_stacksize(a));
			data->i_group += data->size_group;
		}
		opti_instr = opti_instructions(data->instructions);
		printf("%s", opti_instr);
		free(opti_instr);
	}
	else if (ac > 3)
	{
		push_5(data, &a, &b);
		printf("%s", data->instructions);
		free(data->instructions);
	}
	else if (ac == 3)
	{
		push_3(data, &a, 0);
		printf("%s", data->instructions);
		free(data->instructions);
	}
	else
	{
		sa_sb(a, "sa\n", data);
		printf("%s", data->instructions);
		free(data->instructions);
	}
	// while (a)
	// {
	// 	printf("prev = %-10p	addr = %p -> content = %d\naddr = %p	next = %p\n-----------------\n", a->prev, a, a->content, a, a->next);
	// 	a = a->next;
	// }
	ft_free_stack(a);
	// printf("------------------------\n");
	// printf("\n\nstack b\n\n");
	// while (b)
	// {
	// 	printf("prev = %-10p	addr = %p -> content = %d\naddr = %p	next = %p\n-----------------\n", b->prev, b, b->content, b, b->next);
	// 	b = b->next;
	// }
	free(data->sort_tab);
	free(data);
	return (0);
}
