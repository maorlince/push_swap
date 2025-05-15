/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:43:44 by mlemerci          #+#    #+#             */
/*   Updated: 2025/05/15 14:05:04 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		sign;
	long	res;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_atoi(argv[1]));
	printf("%d\n", ft_atoi(argv[2]));
	printf("%d\n", ft_atoi(argv[3]));
	printf("%d\n", ft_atoi(argv[4]));
	printf("%d\n", ft_atoi(argv[5]));
	printf("%d\n", ft_atoi(argv[6]));
	printf("%d\n", ft_atoi(argv[7]));
	printf("%d\n", ft_atoi(argv[8]));
	return(0);
}*/