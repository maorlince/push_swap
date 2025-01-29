/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemerci <mlemerci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:53:39 by mlemerci          #+#    #+#             */
/*   Updated: 2024/12/31 04:17:38 by mlemerci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>

//PRINTF:
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthexa(unsigned int n, char format);
int	ft_putnbr(int n);
int	ft_putstr(const char *s);

//LIBFT:
int ft_atoi(const char *str);
char **ft_split(char const *s, char c);

//PUSH_SWAP:
typedef enum
{
    false,
    true
} bool;

typedef struct stack_element
{
    int value;
    struct stack_element *next;
}stack_element, *stack;

stack new_stack(void);
bool empty_stack(stack b);
stack push_stack(stack a, int v);
stack pop_stack(stack b);
int top_stack(stack b);
int stack_length(stack b);
stack clear_stack(stack b);
void print_stack(stack b);

#endif
