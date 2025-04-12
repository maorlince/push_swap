/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:14:09 by manon             #+#    #+#             */
/*   Updated: 2025/04/11 01:51:43 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_nbr(char *tmp, int n, t_stack *a)
{
	int		j;
	t_stack	s_tmp;

	j = 0;
	while (tmp[j])
	{
		while (tmp[j] == '+' || tmp[j] == '-')
			j++;
		if (!tmp[j])
			return (free(tmp), 0);
		while (ft_isdigit(tmp[j]))
			j++;
		if (tmp[j] != '\0')
			return (free(tmp), 0);
	}
	s_tmp = *a;
	while (s_tmp)
	{
		if (s_tmp->data == n)
			return (0);
		s_tmp = s_tmp->next;
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
	j = 0;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (0);
		while (tmp[j])
		{
			if (tmp[j][0] == '\0')
				return (free_tab(tmp), 0);
			if (!ft_atoi(tmp[j]))
				return (free_tab(tmp), 0);
			n = ft_atoi(tmp[j]);
			verif_nbr(tmp[j], n, a);
		}
		free_tab(tmp);
		i++;
	}
	return (1);
}
/****************************************************************/
//-tri pour 3
//void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);

//-tri pour 5
//void	sort_medium_stack(t_stack *stack_a, t_stack *stack_b);

//-tri pour 100 a 500 (si possible meme algo)
//void	sort_large_stack(t_stack *stack_a, t_stack *stack_b);

/***************************************************************/
//fonction qui supprime un element en tete de liste
//index int max et int min en fonction de la t_stack

int	main(int argc, char**argv)
{
	t_stack	a;
	t_stack	b;
	int		s_len;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_input(argv, &a))
		return (0);
	s_len = stack_length(a);
	if (s_len <= 3)
		ft_printf("small_choice\n");
	//sort_small_stack(a, b);
	if (s_len <= 5 && s_len > 3)
		ft_printf("medium_choice\n");
	//sort_medium_stack(a, b);
	if (s_len > 5)
		ft_printf("large_choice\n");
	//sort_large_stack(a, b);
	print_stack(a);
	free_stack (&a);
	free_stack (&b);
}
