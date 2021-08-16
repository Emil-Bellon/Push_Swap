/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:17:24 by ebellon           #+#    #+#             */
/*   Updated: 2021/08/15 17:56:31 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef	struct	s_data
{
	int		size;
	int		*sort_tab;
	int		nb_group;
	int		size_group;
	int		i_group;
	char	*instructions;	
}				t_data;


t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackfirst(t_stack *stack);
int		ft_stacksize(t_stack *stack);
int		ft_in_stack(t_stack *stack, int content);
void	ft_free_stack(t_stack *stack);
void	sa_sb(t_stack *stack, char *ope, t_data *data);
void	pa_pb(t_stack **from, t_stack **to, char *ope, t_data *data);
void	ra_rb(t_stack **stack, char *ope, t_data *data);
void	rra_rrb(t_stack **stack, char *ope, t_data *data);

#endif
