/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:07:21 by ebellon           #+#    #+#             */
/*   Updated: 2021/10/06 15:30:31 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

int	*ft_check_tab(t_data *data, int ac, int *tab, int sort)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (++j < ac)
		{
			if (i != j && tab[i] == tab[j])
			{
				free(tab);
				free(data);
				printf("Error\n-> There are duplicates\n");
				exit(1);
			}
		}
	}
	if (sort == 1)
		return (tab);
	free(tab);
	free(data);
	exit(0);
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
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] && ft_isdigit(str[i + 1]))
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
			new = ft_stacknew(ft_atoi(av[i]));
			ft_stackadd_back(&fst, new);
			i++;
		}
	}
	return (fst);
}
