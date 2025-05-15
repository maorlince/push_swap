/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemerci <mlemerci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:53:39 by mlemerci          #+#    #+#             */
/*   Updated: 2025/05/14 20:47:43 by mlemerci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

//PRINTF:
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthexa(unsigned int n, char format);
int	ft_putnbr(int n);
int	ft_putstr(const char *s);

#endif
