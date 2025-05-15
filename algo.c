/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:18:18 by manon             #+#    #+#             */
/*   Updated: 2025/05/15 19:00:36 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_stack *a)
{
	if ((*a)->nxt->data > (*a)->nxt->nxt->data && (*a)->nxt->data > (*a)->data)
		reverse_rotate(a, 1);
	if ((*a)->data > (*a)->nxt->data && (*a)->data > (*a)->nxt->nxt->data)
		rotate(a, 1);
	if ((*a)->data > (*a)->nxt->data)
		swap(a, 1);
	return ;
}

void	sort_medium_stack(t_stack *a)
{
	if (!a || !*a || !(*a)->nxt || !(*a)->nxt->nxt || !(*a)->nxt->nxt->nxt)
		return ;
	while (!verif(a))
	{
		while ((*a)->data > (*a)->nxt->data)
		{
			swap(a, 1);
			if ((*a)->nxt->data > (*a)->nxt->nxt->data
				&& (*a)->nxt->data < (*a)->nxt->nxt->nxt->data)
				rotate(a, 1);
		}
		if (!verif(a))
			reverse_rotate(a, 1);
		if ((*a)->data < (*a)->nxt->nxt->nxt->nxt->data)
			reverse_rotate(a, 1);
	}
	return ;
}//23154
//42315 24315  52431 25431 12543
void	sort_large_stack(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		s_len;
	int		max_bits;

	indexation(*a);
	s_len = stack_length(*a);
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits && !verif(a))
	{
		j = 0;
		while (j < s_len)
		{
			if (((*a)->index >> i) & 1)
				rotate(a, 1);
			else
				push(b, a, 2);
			j++;
		}
		while (*b)
			push(a, b, 1);
		i++;
	}
}
