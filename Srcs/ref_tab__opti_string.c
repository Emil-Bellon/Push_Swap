/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_tab__opti_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:51:52 by ebellon           #+#    #+#             */
/*   Updated: 2021/09/29 16:17:46 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

static int	swap(int *tab, int j)
{
	int	swap;

	swap = tab[j];
	tab[j] = tab[j + 1];
	tab[j + 1] = swap;
	return (1);
}

int	*init_sort_tab(int ac, char **av, int av_mal, t_data *data)
{
	int	*tab;
	int	i;
	int	j;
	int	sort;

	j = 0;
	i = 0;
	tab = malloc(sizeof(int) * ac);
	if (tab == NULL)
		return (NULL);
	while (j < ac)
		tab[i++] = ft_atoi_ps(av[j++], tab, av, av_mal);
	i = -1;
	sort = 0;
	while (++i < ac)
	{
		j = -1;
		while (++j < ac - i - 1)
		{
			if (tab[j] > tab[j + 1])
				sort = swap(tab, j);
		}
	}
	return (ft_check_tab(data, ac, tab, sort));
}

static void	search_dumb_instr(char *str, char *instructions, int offset, int i)
{
	int		j;
	int		count_inv;
	int		mem_i;

	j = 0;
	while (str[i])
	{
		count_inv = 0;
		mem_i = i;
		while (str[i] == 'r' && str[i + offset] == 'b')
		{
			i += 4;
			count_inv++;
		}
		if (str[i] != 'p')
			i += count_inv * 4;
		else
			i = mem_i;
		mem_i = 0;
		while (mem_i++ < 4)
			instructions[j++] = str[i++];
	}
	instructions[j] = 0;
}

static char	*erase_spaces(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = ft_calloc(ft_strlen(str), sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			ret[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (ret);
}

char	*opti_instructions(char *str)
{
	char	*instructions;

	instructions = ft_calloc(ft_strlen(str), sizeof(char));
	if (instructions == NULL)
		return (NULL);
	search_dumb_instr(str, instructions, 1, 0);
	free(str);
	str = ft_strdup(instructions);
	if (str == NULL)
		return (NULL);
	free(instructions);
	instructions = ft_calloc(ft_strlen(str), sizeof(char));
	if (instructions == NULL)
		return (NULL);
	search_dumb_instr(str, instructions, 2, 0);
	free(str);
	instructions = erase_spaces(instructions);
	return (instructions);
}
