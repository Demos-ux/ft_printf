/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:26:07 by dsisli            #+#    #+#             */
/*   Updated: 2026/01/20 17:11:27 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_helper(long num)
{
	char	c;

	if (num >= 10)
	{
		ft_putnbr_helper(num / 10);
	}
	c = (num % 10) + '0';
	write(1, &c, 1);
}

static int	ft_numlen(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_putunint(t_format *fmt)
{
	unsigned int	n;
	int				len;
	int				c;

	n = va_arg(fmt->ap, unsigned int);
	len = ft_numlen(n);
	if (n >= 10)
	{
		ft_putnbr_helper(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (len);
}
