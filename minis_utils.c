/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minis_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemerci <mlemerci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:19:20 by mlemerci          #+#    #+#             */
/*   Updated: 2025/05/07 15:20:18 by mlemerci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack *a, int n)
{
	t_stack	tmp;
	t_stack	last;

	if (a == NULL || *a == NULL || (*a)->nxt == NULL)
		return (0);
	last = *a;
	tmp = NULL;
	while (last->nxt != NULL)
	{
		tmp = last;
		last = last->nxt;
	}
	tmp->nxt = NULL;
	last->nxt = *a;
	*a = last;
	if (n == 1)
		ft_printf("rra\n");
	if (n == 2)
		ft_printf("rrb\n");
	return (1);
}

int	reverse_rotate_both(t_stack *a, t_stack *b)
{
	int	rerote_a;
	int	rerote_b;

	if (a == NULL || *a == NULL || (*a)->nxt == NULL
		|| b == NULL || *b == NULL || (*b)->nxt == NULL)
		return (0);
	rerote_a = (reverse_rotate(a, 0));
	rerote_b = (reverse_rotate(b, 0));
	if (rerote_a == 0 && rerote_b == 0)
		return (0);
	ft_printf("rrr\n");
	return (1);
}

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
