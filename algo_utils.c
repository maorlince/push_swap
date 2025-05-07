/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:47:04 by manon             #+#    #+#             */
/*   Updated: 2025/05/07 08:57:51 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif(t_stack *a)
{
	t_stack	tmp;

	if (!a || !*a)
		return (0);
	tmp = *a;
	while (tmp && tmp->nxt)
	{
		if (tmp->data > tmp->nxt->data)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}

int	verif_reverse(t_stack *b)
{
	t_stack	tmp;

	if (!b || !*b)
		return (0);
	tmp = *b;
	while (tmp && tmp->nxt)
	{
		if (tmp->data < tmp->nxt->data)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}

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

int get_max_bits(t_stack *a)
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

//void	sort_medium_stack(t_stack *a)
//{
//	if (!a || !*a || !(*a)->nxt || !(*a)->nxt->nxt|| !(*a)->nxt->nxt->nxt)
//		return ;
//	while(!verif(a))
//	{
//		if ((*a)->nxt->data > (*a)->nxt->nxt->data)
//		{
//			if ((*a)->nxt->data > (*a)->nxt->nxt->nxt->data)
//			{
//				if ((*a)->data > (*a)->nxt->data)
//					swap(a, 1);
//			}
//			rotate(a, 1);
//			if ((*a)->data > (*a)->nxt->data)
//				swap(a, 1);
//		}
//		
//		if (!verif(a) && ((*a)->nxt->data < (*a)->nxt->nxt->data || (*a)->data > (*a)->nxt->nxt->nxt->data))
//			reverse_rotate(a, 1);
//		if ((*a)->data > (*a)->nxt->data)
//			swap(a, 1);
//		if (!(*a)->nxt->nxt->nxt->nxt && (*a)->data > (*a)->nxt->nxt->data)
//			reverse_rotate(a, 1);
//
//		if ((*a)->nxt->nxt->data > (*a)->nxt->nxt->nxt->data)
//		{
//			rotate(a, 1);
//			rotate(a, 1);
//			if((*a)->nxt->data > (*a)->nxt->nxt->data && (*a)->nxt->nxt->data > (*a)->nxt->nxt->nxt->data)
//				swap(a, 1);
//			else if ((*a)->data > (*a)->nxt->nxt->data)
//				rotate(a, 1);
//			if ((*a)->data > (*a)->nxt->data)
//				swap(a, 1);
//		}
//		if (!verif(a) && ((*a)->nxt->data < (*a)->nxt->nxt->data || (*a)->data > (*a)->nxt->nxt->nxt->data))
//			reverse_rotate(a, 1);
//		if ((*a)->data > (*a)->nxt->data)
//			swap(a, 1);
//		if (!(*a)->nxt->nxt->nxt->nxt && (*a)->data > (*a)->nxt->nxt->data)
//			reverse_rotate(a, 1);
//	}
//	return ;
//}
		
//
//void	sort_medium_stack(t_stack *a)
//{
//	if (!a || !*a || !(*a)->nxt || !(*a)->nxt->nxt|| !(*a)->nxt->nxt->nxt)
//		return ;
//
//	while (!verif(a)) //12..3 54321  34215
//	{
//		if ((*a)->data > (*a)->nxt->data)
//		{
//			if ((*a)->data < (*a)->nxt->nxt->data)
//				swap(a, 1);
//			rotate(a, 1);
//		}
//		else
//			reverse_rotate(a, 1);
//		if ((*a)->data > (*a)->nxt->data)
//			swap(a, 1);
//
//
//		if ((*a)->data > (*a)->nxt->data || (*a)->nxt->data > (*a)->nxt->nxt->data)
//		{
//			if ((*a)->data > (*a)->nxt->nxt->data || (*a)->nxt->data > (*a)->nxt->nxt->data)
//				rotate(a, 1);
//			if ((*a)->data > (*a)->nxt->data)
//				swap(a, 1);
//		}
//		if ((*a)->nxt->nxt->nxt->nxt)
//			{
//				if ((*a)->nxt->nxt->nxt->data > (*a)->nxt->nxt->nxt->nxt->data)
//					reverse_rotate(a, 1);
//			}
//		if ((*a)->nxt->nxt->data > (*a)->nxt->nxt->nxt->data)
//			reverse_rotate(a, 1);
//		if ((*a)->data > (*a)->nxt->data)
//				swap(a, 1);
//
//		while ((*a)->data > (*a)->nxt->data)
//		{
//			swap(a, 1);
//			if ((*a)->nxt->data > (*a)->nxt->nxt->data 
//			&& (*a)->nxt->data < (*a)->nxt->nxt->nxt->data)
//			{
//				rotate(a, 1);
//				if ((*a)->nxt->nxt->nxt->nxt)
//					rotate(a, 1);
//			}	
//		}
//		if ((*a)->nxt->nxt->nxt->nxt)
//		if (!verif(a))
//			reverse_rotate(a, 1);
//	}
//	return ;
//}
