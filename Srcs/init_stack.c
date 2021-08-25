/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:07:21 by ebellon           #+#    #+#             */
/*   Updated: 2021/08/25 19:09:56 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

static int	ft_in_stack(t_stack *stack, int content)
{
	while (stack)
	{
		if (stack->content == content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

static void	ft_atoi_failed(int *tab, char **av, int av_mal)
{
	int	i;

	free(tab);
	i = 0;
	if (av_mal == 1)
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	printf("Error : args should only be int input as digit\n");
	exit(1);
}

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
	if (i > 11 || i < (int)ft_strlen(str) || err == 1
		|| (nb > INT_MAX && sign == 1) || (nb > 2147483648 && sign == -1))
		ft_atoi_failed(tab, av, av_mal);
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
