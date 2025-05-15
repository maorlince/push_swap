/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemerci <mlemerci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:08:39 by manon             #+#    #+#             */
/*   Updated: 2025/05/15 04:45:49 by mlemerci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_nbr(char *tmp, long n, t_stack *a)
{
	int		j;
	t_stack	s_tmp;

	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == '+' || tmp[j] == '-')
			j++;
		if (!tmp || !tmp[j] || tmp[j] == '\0'
			|| (n > 2147483647 || n < -2147483648))
			return (0);
		while (ft_isdigit(tmp[j]))
			j++;
		if (tmp[j] != '\0' || j >= 12)
			return (0);
	}
	s_tmp = *a;
	while (s_tmp)
	{
		if (s_tmp->data == n)
			return (0);
		s_tmp = s_tmp->nxt;
	}
	add_to_stack(a, n);
	return (1);
}

int	parse_input(char **argv, t_stack *a)
{
	int		i;
	int		j;
	int		n;
	char	**tmp;

	i = 1;
	while (argv[i] != NULL)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (free(tmp), ft_printf("Error: Init tmp by split\n"));
		j = 0;
		while (tmp[j])
		{
			if (tmp[j][0] == '\0')
				return (free_tab(tmp), ft_printf("Error: Void argument\n"));
			n = ft_atoi(tmp[j]);
			if (!verif_nbr(tmp[j], n, a))
				return (free_tab(tmp), ft_printf("Error: Invalid number\n"));
			j++;
		}
		free_tab(tmp);
		i++;
	}
	return (1);
}

//print_stack(a);
int	main(int argc, char**argv)
{
	t_stack	a;
	t_stack	b;
	int		s_len;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (parse_input(argv, &a) != 1)
		exit (0);
	s_len = stack_length(a);
	if (s_len == 2 && a->data > a->nxt->data)
		swap(&a, 1);
	if (s_len == 3)
		sort_small_stack(&a);
	if (s_len <= 5 && s_len > 3)
		sort_medium_stack(&a);
	if (s_len > 5)
		sort_large_stack(&a, &b);
	free_stack (a);
	free_stack (b);
}
