/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:08:45 by dsisli            #+#    #+#             */
/*   Updated: 2025/10/30 15:47:39 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_helper(long num);
static int	ft_numlen(long num);

int	ft_putnbr(t_format *fmt)
{
	int		n;
	long	num;
	char	c;
	int		len;

	n = va_arg(fmt->ap, int);
	num = n;
	len = ft_numlen(num);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_helper(num / 10);
	}
	c = (num % 10) + '0';
	write(1, &c, 1);
	return (len);
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
