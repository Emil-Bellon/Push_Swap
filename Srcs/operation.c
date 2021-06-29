/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:40:47 by ebellon           #+#    #+#             */
/*   Updated: 2021/06/29 18:05:28 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

void	sa_sb(t_stack *stack, char *ope)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = (stack->next)->content;
		(stack->next)->content = tmp;
		printf("%s\n", ope);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa_sb(a, "sa");
	sa_sb(b, "sb");
}

void	pa_pb(t_stack **from, t_stack **to, char *ope)
{
	t_stack	*tmp;
	
	if (*from)
	{
		tmp = *from;
		*from = (*from)->next;
		if (*from)
			(*from)->prev = NULL;
		if (*to)
			ft_stackadd_front(to, tmp);
		else
			*to = ft_stacknew(tmp->content);
		printf("%s\n", ope);
	}
}

void	ra_rb(t_stack **stack, char *ope)
{
	t_stack *tmp;
	t_stack *last;

	if (*stack)
	{
		tmp = *stack;
		last = ft_stacklast(*stack);
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		printf("%s\n", ope);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra_rb(a, "ra");
	ra_rb(b, "rb");
}

void	rra_rrb(t_stack **stack, char *ope)
{
	t_stack *tmp;

	if (*stack)
	{
		tmp = ft_stacklast(*stack);
		(tmp->prev)->next = NULL;
		tmp->prev = NULL;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		(*stack) = tmp;
		printf("%s\n", ope);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra_rrb(a, "rra");
	rra_rrb(b, "rrb");
}