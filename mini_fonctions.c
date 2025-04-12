/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:41:02 by manon             #+#    #+#             */
/*   Updated: 2025/04/11 01:14:17 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
int	swap_a(t_stack *a)
{
	t_stack	tmp;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return (0);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	return (1);
}
// sb

int	swap_b(t_stack *b)
{
	t_stack	tmp;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return (0);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	return (1);
}

// ss : sa et sb en même temps.
int	swap_both(t_stack *a, t_stack *b)
{
	int	new_a;
	int	new_b;

	new_a = swap_a(a);
	new_b = swap_b(b);
	if (new_a == 0 && new_b == 0)
		return (0);
	return (1);
}

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
int	push_a(t_stack *a, t_stack *b)
{
	t_stack	tmp;

	if (b == NULL || *b == NULL )
		return (0);
	tmp = *b;
	*b = (*b)->next;
	(tmp)->next = *a;
	*a = tmp;
	return (1);
}

//pb
int	push_b(t_stack *b, t_stack *a)
{
	t_stack	tmp;

	if (a == NULL || *a == NULL )
		return (0);
	tmp = *a;
	*a = (*a)->next;
	(tmp)->next = *b;
	*b = tmp;
	return (1);
}

// ra (rotate a) : Décale vers le haut les élements de la pile a.
// Le premier élément devient le dernier.
int	rotate_a(t_stack *a)
{
	t_stack	tmp;
	t_stack	current;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return (0);
	tmp = *a;
	*a = (*a)->next;
	current = *a;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	return (1);
}
// rb

int	rotate_b(t_stack *b)
{
	t_stack	tmp;
	t_stack	current;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return (0);
	tmp = *b;
	*b = (*b)->next;
	current = *b;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	return (1);
}

//rr : ra et rb en même temps.
int	rotate_both(t_stack *a, t_stack *b)
{
	int	new_a;
	int	new_b;

	new_a = rotate_a(a);
	new_b = rotate_b(b);
	if (new_a == 0 && new_b == 0)
		return (0);
	return (1);
}

//rra (reverse rotate a) : Décale vers le bas tous les élements de la pile a.
//Le dernier élément devient le premier.
int	reverse_rotate_a(t_stack *a)
{
	t_stack	tmp;
	t_stack	last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return (0);
	last = *a;
	tmp = NULL;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	return (1);
}
// rrb

int	reverse_rotate_b(t_stack *b)
{
	t_stack	tmp;
	t_stack	last;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return (0);
	last = *b;
	tmp = NULL;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	return (1);
}

//rrr : rra et rrb en même temps.
int	reverse_rotate_both(t_stack *a, t_stack *b)
{
	int	rerote_a;
	int	rerote_b;

	if (a == NULL || *a == NULL || (*a)->next == NULL
		|| b == NULL || *b == NULL || (*b)->next == NULL)
		return (0);
	rerote_a = (reverse_rotate_a(a));
	rerote_b = (reverse_rotate_b(b));
	if (rerote_a == 0 && rerote_b == 0)
		return (0);
	return (1);
}
