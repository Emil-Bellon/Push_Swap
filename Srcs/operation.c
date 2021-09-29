/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:40:47 by ebellon           #+#    #+#             */
/*   Updated: 2021/09/29 16:15:10 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*join;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_memcpy(ft_memcpy(join, s1, len1) + len1, s2, len2 + 1);
	if (s1)
		free(s1);
	return (join);
}

void	sa_sb(t_stack *stack, char *ope, t_data *data)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = (stack->next)->content;
		(stack->next)->content = tmp;
		data->instructions = ft_strjoin_free(data->instructions, ope);
	}
}

void	pa_pb(t_stack **from, t_stack **to, char *ope, t_data *data)
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
		{
			*to = ft_stacknew(tmp->content);
			free(tmp);
		}
		data->instructions = ft_strjoin_free(data->instructions, ope);
	}
}

void	ra_rb(t_stack **stack, char *ope, t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack)
	{
		tmp = *stack;
		last = ft_stacklast(*stack);
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		data->instructions = ft_strjoin_free(data->instructions, ope);
	}
}

void	rra_rrb(t_stack **stack, char *ope, t_data *data)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = ft_stacklast(*stack);
		(tmp->prev)->next = NULL;
		tmp->prev = NULL;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		(*stack) = tmp;
		data->instructions = ft_strjoin_free(data->instructions, ope);
	}
}
