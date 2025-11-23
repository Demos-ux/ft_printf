/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:10:14 by dsisli            #+#    #+#             */
/*   Updated: 2025/10/30 15:47:14 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putbhex_recursive(unsigned int n)
{
	char	*hex;
	int		count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count += putbhex_recursive(n / 16);
	}
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_putbhex(t_format *fmt)
{
	unsigned int	n;

	n = va_arg(fmt->ap, unsigned int);
	return (putbhex_recursive(n));
}
