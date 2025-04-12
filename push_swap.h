/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:43:31 by manon             #+#    #+#             */
/*   Updated: 2025/04/12 13:16:43 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

//PUSH_SWAP_STRUCT
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}t_STACK,	*t_stack;

//mini_fonctions
int		swap_a(t_stack *a);
int		swap_b(t_stack *b);
int		swap_both(t_stack *a, t_stack *b);
int		push_a(t_stack *a, t_stack *b);
int		push_b(t_stack *b, t_stack *a);
int		rotate_a(t_stack *a);
int		rotate_b(t_stack *b);
int		rotate_both(t_stack *a, t_stack *b);
int		reverse_rotate_a(t_stack *a);
int		reverse_rotate_b(t_stack *b);
int		reverse_rotate_both(t_stack *a, t_stack *b);

//utils
int		add_to_stack(t_stack *a, int data);
int		print_stack(t_stack a);
int		stack_length(t_stack a);
void	free_stack(t_stack *a);
void	free_tab(char **tmp);

#endif