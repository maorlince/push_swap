/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemerci <mlemerci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:41:02 by manon             #+#    #+#             */
/*   Updated: 2025/05/07 15:20:21 by mlemerci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *a, int n)
{
	t_stack	tmp;

	if (a == NULL || *a == NULL || (*a)->nxt == NULL)
		return (0);
	tmp = *a;
	*a = (*a)->nxt;
	tmp->nxt = (*a)->nxt;
	(*a)->nxt = tmp;
	if (n == 1)
		ft_printf("sa\n");
	if (n == 2)
		ft_printf("sb\n");
	return (1);
}

int	swap_both(t_stack *a, t_stack *b)
{
	int	new_a;
	int	new_b;

	new_a = swap(a, 0);
	new_b = swap(b, 0);
	if (new_a == 0 && new_b == 0)
		return (0);
	ft_printf("ss\n");
	return (1);
}

int	push(t_stack *a, t_stack *b, int n)
{
	t_stack	tmp;

	if (b == NULL || *b == NULL )
		return (0);
	tmp = *b;
	*b = (*b)->nxt;
	(tmp)->nxt = *a;
	*a = tmp;
	if (n == 1)
		ft_printf("pa\n");
	if (n == 2)
		ft_printf("pb\n");
	return (1);
}

int	rotate(t_stack *a, int n)
{
	t_stack	tmp;
	t_stack	current;

	if (a == NULL || *a == NULL || (*a)->nxt == NULL)
		return (0);
	tmp = *a;
	*a = (*a)->nxt;
	current = *a;
	while (current->nxt != NULL)
		current = current->nxt;
	current->nxt = tmp;
	tmp->nxt = NULL;
	if (n == 1)
		ft_printf("ra\n");
	if (n == 2)
		ft_printf("rb\n");
	return (1);
}

int	rotate_both(t_stack *a, t_stack *b)
{
	int	new_a;
	int	new_b;

	new_a = rotate(a, 0);
	new_b = rotate(b, 0);
	if (new_a == 0 && new_b == 0)
		return (0);
	ft_printf("rr\n");
	return (1);
}
