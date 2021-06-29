/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:28:52 by ebellon           #+#    #+#             */
/*   Updated: 2021/06/29 20:00:28 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/push_swap.h"

t_stack *init_stack(int ac, char **av)
{
	t_stack *fst;
	t_stack	*new;
	int		i;

	fst = NULL;
	i = 2;
	if (ac >= 2)
	{
		fst = ft_stacknew(atoi(av[1]));
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

int	*init_tab(int ac, char **av)
{
	int *tab;
	int	i;
	int j;
	int	swap;

	i = 0;
	j = 1;
	while (j < ac)
		tab[i++] = atoi(av[j++]);
	i = -1;
	while (++i < ac - 1)
	{
		j = -1;
		while (++j < ac - i - 1)
			if (tab[j] > tab[j + 1]) 
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
	}
	return (tab);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
	int		*sort_tab;
	int		ret;
    
    a = init_stack(ac, av);
	sort_tab = init_sort_tab(ac, av);
	for (int c = 0; c < ac - 1; c++)
    	printf("%d\n", sort_tab[c]);
	if (a == NULL)
		return (1);
	b = NULL;
	pa_pb(&a, &b, "pb");
	pa_pb(&a, &b, "pb");
	pa_pb(&a, &b, "pb");
	pa_pb(&a, &b, "pb");
	sa_sb(a, "sa");
	sa_sb(b, "sb");
	ra_rb(&a, "ra");
	pa_pb(&b, &a, "pa");
	pa_pb(&b, &a, "pa");
	pa_pb(&b, &a, "pa");
	pa_pb(&b, &a, "pa");
	while (a)
	{
		printf("prev = %-10p	addr = %p -> content = %d\naddr = %p	next = %p\n-----------------\n", a->prev, a, a->content, a, a->next);
		a = a->next;
	}
	printf("\n\nstack b\n\n");
	while (b)
	{
		printf("prev = %-10p	addr = %p -> content = %d\naddr = %p	next = %p\n-----------------\n", b->prev, b, b->content, b, b->next);
		b = b->next;
	}
	return (0);
}