/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:48:41 by dsisli            #+#    #+#             */
/*   Updated: 2026/01/20 17:33:04 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_format	t_format;

typedef struct s_format
{
	va_list	ap;
	char	*format;
	int		i;
	int		total;
}	t_format;

int	ft_putstr(t_format *fmt);
int	ft_putchar(t_format *fmt);
int	ft_puthex(t_format *fmt);
int	ft_putbhex(t_format *fmt);
int	ft_putnbr(t_format *fmt);
int	ft_formatchecker(t_format *fmt);
int	ft_printf(const char *format, ...);
int	ft_putpercent(t_format *fmt);
int	ft_putpointer(t_format *fmt);
int	ft_putunint(t_format *fmt);

#endif
