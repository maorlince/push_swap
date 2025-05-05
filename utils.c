/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:43:11 by manon             #+#    #+#             */
/*   Updated: 2025/04/17 22:34:06 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack a)
{
	t_stack	temp;

	while (a)
	{
		temp = a;
		a = a->nxt;
		free(temp);
	}
}

void	free_tab(char **tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

int	add_to_stack(t_stack *a, int n)
{
	t_stack	new_node;
	t_stack	tmp;

	tmp = malloc(sizeof(t_STACK));
	if (!tmp)
		return (0);
	tmp->data = n;
	tmp->nxt = NULL;
	if (!*a)
	{
		*a = tmp;
		return (1);
	}
	new_node = *a;
	while (new_node->nxt)
		new_node = new_node->nxt;
	new_node->nxt = tmp;
	return (1);
}

int	print_stack(t_stack a)
{
	while (a != NULL)
	{
		ft_printf("[%d]\n", a->data);
		a = a->nxt;
	}
	return (0);
}

int	stack_length(t_stack a)
{
	int	length;

	length = 0;
	while (a)
	{
		length++;
		a = a->nxt;
	}
	return (length);
}
