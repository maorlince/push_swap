/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:43:31 by manon             #+#    #+#             */
/*   Updated: 2025/05/06 17:45:22 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

//PUSH_SWAP_STRUCT
typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*nxt;
}t_STACK,	*t_stack;

//mini_fonctions
int			swap(t_stack *a, int n);
int			swap_both(t_stack *a, t_stack *b);
int			push(t_stack *a, t_stack *b, int n);
int			rotate(t_stack *a, int n);
int			rotate_both(t_stack *a, t_stack *b);
int			reverse_rotate(t_stack *a, int n);
int			reverse_rotate_both(t_stack *a, t_stack *b);

//utils
int			add_to_stack(t_stack *a, int data);
int			print_stack(t_stack a);
int			stack_length(t_stack a);
void		free_stack(t_stack a);
void		free_tab(char **tmp);

//ALGO_UTILS
int			verif(t_stack *a);
int			verif_reverse(t_stack *a);
//static void	sort_int_tab(int *tab, int s_len);
//static int	get_index(int *tab, int s_len, int value);
void		indexation(t_stack a);
int			get_max_index(t_stack a);
int			get_max_bits(t_stack *a);

//ALGO
void		sort_small_stack(t_stack *a);
void		sort_medium_stack(t_stack *a);
void		sort_large_stack(t_stack *a, t_stack *b);

#endif