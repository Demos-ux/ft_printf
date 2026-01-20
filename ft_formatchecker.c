/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatchecker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:10:56 by dsisli            #+#    #+#             */
/*   Updated: 2026/01/20 17:35:40 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatchecker(t_format *fmt)
{
	char	specifier;

	specifier = fmt->format[fmt->i];
	if (specifier == 'c')
		return (ft_putchar(fmt));
	else if (specifier == 's')
		return (ft_putstr(fmt));
	else if (specifier == 'p')
		return (ft_putpointer(fmt));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(fmt));
	else if (specifier == 'u')
		return (ft_putunint(fmt));
	else if (specifier == 'x')
		return (ft_puthex(fmt));
	else if (specifier == 'X')
		return (ft_putbhex(fmt));
	else if (specifier == '%')
		return (ft_putpercent(fmt));
	return (0);
}
