/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatchecker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:10:56 by dsisli            #+#    #+#             */
/*   Updated: 2026/01/20 14:25:59 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatchecker(t_format *fmt)
{
    t_fmttype	format_types[] = {
        {'c', ft_putchar},
        {'s', ft_putstr},
        {'p', ft_putpointer},
        {'d', ft_putnbr},
        {'i', ft_putnbr},
        {'x', ft_puthex},
        {'X', ft_putbhex},
        {'%', ft_putpercent},
        {'u', ft_putunint},
        {'\0', NULL}
    };
    int			i;
    char		specifier;

    specifier = fmt->format[fmt->i];
    i = 0;
    while (format_types[i].type)
    {
        if (format_types[i].type == specifier)
        {
            return (format_types[i].func(fmt));
        }
        i++;
    }
    return (0);
}
