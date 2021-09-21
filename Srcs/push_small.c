/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:59:27 by ebellon           #+#    #+#             */
/*   Updated: 2021/09/21 14:32:25 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

static void	push_3_part2(t_data *data, t_stack **a, int offset)
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

double	root(double n)
{
	double	lo;
	double	hi;
	double	mid;
	int		i;

	lo = 1;
	hi = n;
	i = -1;
	while (++i < 100)
	{
		mid = (lo + hi) / 2;
		if (mid * mid == n)
			return (mid);
		if (mid * mid > n)
			hi = mid;
		else
			lo = mid;
	}
	return (mid);
}

int	ft_chech_sing_arg(char *str, t_data *data)
{
	int	i;
	int	space_cpt;

	i = 0;
	space_cpt = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
		{
			printf("Error : args should only be int input as digit");
			free(data);
			return (0);
		}
		if (str[i] == ' ')
			space_cpt++;
		i++;
	}
	if (space_cpt == i)
	{
		printf("Error : args should only be int input as digit");
		free(data);
		return (0);
	}
	return (1);
}
