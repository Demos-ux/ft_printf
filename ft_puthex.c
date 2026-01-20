/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:09:43 by dsisli            #+#    #+#             */
/*   Updated: 2025/10/30 15:47:33 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthex_recursive(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += puthex_recursive(n / 16);
	}
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_puthex(t_format *fmt)
{
	unsigned int	n;

	n = va_arg(fmt->ap, unsigned int);
	return (puthex_recursive(n));
}
