/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:17:24 by ebellon           #+#    #+#             */
/*   Updated: 2021/08/25 19:12:12 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data
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
void	ft_free_stack(t_stack *stack);
void	sa_sb(t_stack *stack, char *ope, t_data *data);
void	pa_pb(t_stack **from, t_stack **to, char *ope, t_data *data);
void	ra_rb(t_stack **stack, char *ope, t_data *data);
void	rra_rrb(t_stack **stack, char *ope, t_data *data);
char	*opti_instructions(char *str);
int		*init_sort_tab(int ac, char **av, int av_mal);
int		ft_atoi_ps(const char *str, int *tab, char **av, int av_mal);
void	push_3(t_data *data, t_stack **a, int offset);
void	push_5(t_data *data, t_stack **a, t_stack **b);
void	push_b_group(t_data *data, t_stack **a, t_stack **b);
void	push_a_group(t_data *data, t_stack **a, t_stack **b, int group);
void	ft_free_stack(t_stack *stack);
t_stack	*init_stack(int ac, char **av);
int		ft_atoi_ps(const char *str, int *tab, char **av, int av_mal);

#endif
