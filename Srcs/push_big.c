/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:03:45 by ebellon           #+#    #+#             */
/*   Updated: 2021/08/25 19:04:34 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

static int	content_in_group(t_data *data, int content, int start)
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

static int	rotate_b(int *rot, int size_group, t_stack **b, t_data *data)
{
	ra_rb(b, "rb \n", data);
	*rot += 1;
	if (*rot >= size_group)
		return (0);
	return (1);
}

static int	rotate_inv_b(int *rot, t_stack **b, t_data *data)
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
