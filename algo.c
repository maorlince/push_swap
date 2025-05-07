/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:18:18 by manon             #+#    #+#             */
/*   Updated: 2025/05/07 10:06:40 by manon            ###   ########.fr       */
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
	}
	return ;
}
//tri parfait a 4 a voir pour 5 plus tard

void	sort_large_stack(t_stack *a, t_stack *b)
{
	int		i;
	int 	max_index;

	indexation(*a);
	max_index = get_max_index(*a);
	i = 0;
	while(i <= max_index)
	{
		if((*a)->index > (max_index / 2))
			rotate(a, 1);
		else
			push(b, a, 2);
		i++;
	}
	while(!verif (a) || !verif_reverse(b))
	{
		if ((*a)->data > (*a)->nxt->data && (*b)->data < (*b)->nxt->data)
			swap_both(a, b);
		if ((*a)->data > (*a)->nxt->data && ((*a)->data != max_index / 2))
			swap(a, 1);
		if ((*b)->data < (*b)->nxt->data && (((*b)->data != max_index - 1) && ((*b)->nxt->data != max_index)))
			swap(b, 2);
		if (!verif(a) && !verif_reverse(b))
			rotate_both(a, b);
		if (!verif(a))
			rotate(a, 1);
		if (!verif_reverse(b))
			reverse_rotate(b, 2);
		sleep(1);
	}
	while((*b))
		push(a, b, 1);
}
//2 10 4 3 5 8 7 9 1 6
//2     10 4 3 5 8 7 9 1 6
//2     4 3 5 .... 10
//2 4 3 5     8 7 9 1 6 10
//2 4 3 5     1 6 10 8 7 9
//1 5 3 4 2    6 10 8 7 9
//..           10 8 7 9 6
//5 1 3 4 2    8 10 7 9 6
//1 3 4 2 5    10 7 9 6 8
//...          7 9 6 8 10
//...          9 6 8 10 7

//-tri pour 100(700 coups) a 500(5500) (si possible meme algo) cd ..

//void	sort_large_stack(t_stack *a, t_stack *b)
//{
//	int		i;
//	int		j;
//	int		s_len;
//	int		max_bits;
//
//	indexation(*a);
//	s_len = stack_length(*a);
//	max_bits = get_max_bits(a);
//	i = 0;
//	while (i < max_bits)
//	{
//		j = 0;
//		while (j < s_len)
//		{
//			if (((*a)->index >> i) & 1)
//				rotate(a, 1);
//			else
//				push(b, a, 2);
//			j++;
//		}
//		while (*b)
//			push(a, b, 1);
//		i++;
//	}
//}