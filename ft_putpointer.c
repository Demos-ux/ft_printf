/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:22:05 by dsisli            #+#    #+#             */
/*   Updated: 2025/10/30 15:47:58 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putaddr_recursive(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += putaddr_recursive(n / 16);
	}
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_putpointer(t_format *fmt)
{
	unsigned long	p;

	p = (unsigned long)va_arg(fmt->ap, void *);
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		return (2 + putaddr_recursive(p));
	}
}
