/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemerci <mlemerci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:47:04 by manon             #+#    #+#             */
/*   Updated: 2025/05/07 15:20:36 by mlemerci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_int_tab(int *tab, int s_len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < s_len - 1)
	{
		j = i + 1;
		while (j < s_len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_index(int *tab, int s_len, int value)
{
	int	i;

	i = 0;
	while (i < s_len)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	indexation(t_stack a)
{
	int		s_len;
	int		*tab;
	int		i;
	t_stack	tmp;

	s_len = stack_length(a);
	tmp = a;
	i = 0;
	tab = malloc(sizeof(int) * s_len);
	if (!tab)
		return ;
	while (tmp)
	{
		tab[i++] = tmp->data;
		tmp = tmp->nxt;
	}
	sort_int_tab(tab, s_len);
	tmp = a;
	while (tmp)
	{
		tmp->index = get_index(tab, s_len, tmp->data);
		tmp = tmp->nxt;
	}
	free(tab);
}

int	get_max_index(t_stack a)
{
	int		max;

	if (!a)
		return (0);
	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->nxt;
	}
	return (max);
}

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	if (!a || !*a)
		return (0);
	max = get_max_index(*a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
