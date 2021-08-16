/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:28:52 by ebellon           #+#    #+#             */
/*   Updated: 2021/08/16 02:31:52 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

t_stack *init_stack(int ac, char **av)
{
	t_stack *fst;
	t_stack	*new;
	int		i;

	fst = NULL;
	i = 1;
	if (ac >= 2)
	{
		fst = ft_stacknew(atoi(av[0]));
		while (i < ac)
		{
			if (ft_in_stack(fst, atoi(av[i])) == 1)
			{
				ft_free_stack(fst);
				printf("Error\n-> There are duplicates\n");
				return (NULL);
			}	
			new = ft_stacknew(atoi(av[i]));
			ft_stackadd_back(&fst, new);
			i++;
		}
	}
	return (fst);
}

int	*init_sort_tab(int ac, char **av)
{
	int *tab;
	int	i;
	int j;
	int	swap;
	int sort;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * ac);
	while (j < ac)
		tab[i++] = atoi(av[j++]);
	i = -1;
	sort = 0;
	while (++i < ac)
	{
		j = -1;
		while (++j < ac - i - 1)
			if (tab[j] > tab[j + 1]) 
			{
				sort = 1;
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
	}
	if (sort == 0)
	{
		free(tab);
		exit(0);
	}
	return (tab);
}

int		content_in_group(t_data *data, int content, int start)
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
	while (ft_stacksize(*b) < data->size && ft_stacksize(*b) < (data->i_group + 1) * data->size_group)
	{
		if (content_in_group(data, (*a)->content, data->i_group * data->size_group) == 1)
			pa_pb(a, b, "pb \n", data);
		else
			rra_rrb(a, "rra\n", data);
	}
}

void	push_a_group(t_data *data, t_stack **a, t_stack **b, int group)
{
	int i;
	int rot;
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
		{
			ra_rb(b, "rb \n", data);
			rot++;
			if (rot >= size_group)
				dir_rot = 0;
		}
		else if (dir_rot == 0)
		{
			rra_rrb(b, "rrb\n", data);
			rot--;
			if (rot <= 0)
				dir_rot = 1;
		}
	}
}

char	*opti_instructions(char *str)
{
	int		i;
	int		j;
	int		count_inv;
	char	*instructions;
	int		mem_i;

	i = 0;
	j = 0;
	instructions = ft_calloc(ft_strlen(str), sizeof(char));
	while (str[i])
	{
		count_inv = 0;
		mem_i = i;
		while (str[i] == 'r' && str[i + 1] == 'b')
		{
			i += 4;
			count_inv++;
		}
		if (str[i] != 'p')
			i += count_inv * 4;
		else
			i = mem_i;
		mem_i = 0;
		while (mem_i < 4)
		{
			instructions[j++] = str[i++];
			mem_i++;
		}
	}
	free(str);
	str = ft_strdup(instructions);
	i = 0;
	j = 0;
	while (str[i])
	{
		count_inv = 0;
		mem_i = i;
		while (str[i] == 'r' && str[i + 2] == 'b')
		{
			i += 4;
			count_inv++;
		}
		if (str[i] != 'p')
			i += count_inv * 4;
		else
			i = mem_i;
		mem_i = 0;
		while (mem_i < 4)
		{
			instructions[j++] = str[i++];
			mem_i++;
		}
	}
	instructions[j] = 0;
	return (instructions);
}

void	push_3(t_data *data, t_stack **a, int offset)
{
	if ((*a)->content == data->sort_tab[0 + offset] && (*a)->next->content == data->sort_tab[2 + offset] && (*a)->next->next->content == data->sort_tab[1 + offset])
	{
		sa_sb(*a, "sa \n", data);
		ra_rb(a, "ra \n", data);
	}
	else if ((*a)->content == data->sort_tab[1 + offset] && (*a)->next->content == data->sort_tab[0 + offset] && (*a)->next->next->content == data->sort_tab[2 + offset])
		sa_sb(*a, "sa \n", data);
	else if ((*a)->content == data->sort_tab[1 + offset] && (*a)->next->content == data->sort_tab[2 + offset] && (*a)->next->next->content == data->sort_tab[0 + offset])
		rra_rrb(a, "rra\n", data);
	else if ((*a)->content == data->sort_tab[2 + offset] && (*a)->next->content == data->sort_tab[1 + offset] && (*a)->next->next->content == data->sort_tab[0 + offset])
	{
		sa_sb(*a, "sa \n", data);
		rra_rrb(a, "rra\n", data);
	}
	else if ((*a)->content == data->sort_tab[2 + offset] && (*a)->next->content == data->sort_tab[0 + offset] && (*a)->next->next->content == data->sort_tab[1 + offset])
		ra_rb(a, "ra \n", data);
}

void	push_5(t_data *data, t_stack **a, t_stack **b)
{
	int	i;
	
	i = 0;
	while (ft_stacksize(*b) < 2)
	{
		if ((*a)->content == data->sort_tab[i])
		{
			pa_pb(a, b, "pb \n", data);
			i++;
		}
		else if ((*a)->next->content == data->sort_tab[i] || (*a)->next->next->content == data->sort_tab[i])
			ra_rb(a, "ra \n", data);
		else
			rra_rrb(a, "ra \n", data);
	}
	push_3(data, a, 2);
	pa_pb(b, a, "pa \n", data);
	pa_pb(b, a, "pa \n", data);
}

int main(int ac1, char **av1)
{
    t_stack *a;
	t_stack *b;
	t_data	*data;
	char	**av;
	int		ac;

	(void)ac1;
	av = ft_split(av1[1], ' ');
	ac = 0;
	while (av[ac])
		ac++;
	data = malloc(sizeof(t_data));
	data->sort_tab = init_sort_tab(ac, av);
	// for (int i = 0; i < ac; i++)
	// 	printf("tab[%d] = %d\n", i, data->sort_tab[i]);
    a = init_stack(ac, av);
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
		printf("%s", opti_instructions(data->instructions));
	}
	else if (ac > 3)
	{
		push_5(data, &a, &b);
		printf("%s", data->instructions);
	}
	else 
	{
		push_3(data, &a, 0);
		printf("%s", data->instructions);
	}
	// push_a_group(data, &a, &b, 4);
	// data->i_group = 2;
	// push_a_group(data, &a, &b, 3);
	// data->i_group = 3;
	// push_a_group(data, &a, &b, 2);
	// data->i_group = 4;
	// push_a_group(data, &a, &b, 1);
	// while (a)
	// {
	// 	printf("prev = %-10p	addr = %p -> content = %d\naddr = %p	next = %p\n-----------------\n", a->prev, a, a->content, a, a->next);
	// 	a = a->next;
	// }
	// printf("------------------------\n");
	// printf("\n\nstack b\n\n");
	// while (b)
	// {
	// 	printf("prev = %-10p	addr = %p -> content = %d\naddr = %p	next = %p\n-----------------\n", b->prev, b, b->content, b, b->next);
	// 	b = b->next;
	// }
	return (0);
}