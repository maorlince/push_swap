/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:43:11 by manon             #+#    #+#             */
/*   Updated: 2025/04/11 01:14:04 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_stack	current;
	t_stack	next_node;

	current = *a;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*a = NULL;
}

void	free_tab(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	i--;
	while (tmp[i])
	{
		free(tmp[i]);
		i--;
	}
	free(tmp);
}

int	add_to_stack(t_stack *a, int n)
{
	t_stack	new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->data = n;
	new_node->next = *a;
	*a = new_node;
	return (1);
}

int	print_stack(t_stack a)
{
	while (a != NULL)
	{
		ft_printf("[%d]\n");
		a = a->next;
	}
	return (0);
}

int	stack_length(t_stack a)
{
	int	length;

	length = 0;
	while (a != NULL)
	{
		length++;
		a = a->next;
	}
	return (length);
}
