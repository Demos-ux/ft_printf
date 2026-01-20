/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:41:59 by dsisli            #+#    #+#             */
/*   Updated: 2026/01/20 17:16:53 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_format	fmt;

	fmt.format = (char *)format;
	fmt.total = 0;
	fmt.i = 0;
	va_start(fmt.ap, format);
	while (fmt.format[fmt.i])
	{
		if (fmt.format[fmt.i] == '%')
		{
			fmt.i++;
			fmt.total += ft_formatchecker(&fmt);
		}
		else
		{
			write(1, &fmt.format[fmt.i], 1);
			fmt.total++;
		}
		fmt.i++;
	}
	va_end(fmt.ap);
	return (fmt.total);
}
// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

// int main(void)
// {
//     int ret;
//     char *str = "Hello World";
//     char *null_str = NULL;
//     void *ptr = &ret;
//     void *null_ptr = NULL;

//     printf("Testing ft_printf with various edge cases:\n\n");

//     // Basic string
//     printf("1. Basic string:\n");
//     ret = ft_printf("Hello World\n");
//     printf("Return value: %d\n\n", ret);

//     // %s with normal string
//     printf("2. %%s with normal string:\n");
//     ret = ft_printf("String: %s\n", str);
//     printf("Return value: %d\n\n", ret);

//     // %s with NULL string
//     printf("3. %%s with NULL string:\n");
//     ret = ft_printf("String: %s\n", null_str);
//     printf("Return value: %d\n\n", ret);

//     // %s with empty string
//     printf("4. %%s with empty string:\n");
//     ret = ft_printf("String: %s\n", "");
//     printf("Return value: %d\n\n", ret);

//     // %c with normal char
//     printf("5. %%c with normal char:\n");
//     ret = ft_printf("Char: %c\n", 'A');
//     printf("Return value: %d\n\n", ret);

//     // %c with null char
//     printf("6. %%c with null char:\n");
//     ret = ft_printf("Char: %c\n", '\0');
//     printf("Return value: %d\n\n", ret);

//     // %d with positive int
//     printf("7. %%d with positive int:\n");
//     ret = ft_printf("Int: %d\n", 42);
//     printf("Return value: %d\n\n", ret);

//     // %d with negative int
//     printf("8. %%d with negative int:\n");
//     ret = ft_printf("Int: %d\n", -42);
//     printf("Return value: %d\n\n", ret);

//     // %d with zero
//     printf("9. %%d with zero:\n");
//     ret = ft_printf("Int: %d\n", 0);
//     printf("Return value: %d\n\n", ret);

//     // %d with INT_MAX
//     printf("10. %%d with INT_MAX:\n");
//     ret = ft_printf("Int: %d\n", INT_MAX);
//     printf("Return value: %d\n\n", ret);

//     // %d with INT_MIN
//     printf("11. %%d with INT_MIN:\n");
//     ret = ft_printf("Int: %d\n", INT_MIN);
//     printf("Return value: %d\n\n", ret);

//     // %i with positive int
//     printf("12. %%i with positive int:\n");
//     ret = ft_printf("Int: %i\n", 42);
//     printf("Return value: %d\n\n", ret);

//     // %i with negative int
//     printf("13. %%i with negative int:\n");
//     ret = ft_printf("Int: %i\n", -42);
//     printf("Return value: %d\n\n", ret);

//     // %x with positive hex
//     printf("14. %%x with positive hex:\n");
//     ret = ft_printf("Hex: %x\n", 255);
//     printf("Return value: %d\n\n", ret);

//     // %x with zero
//     printf("15. %%x with zero:\n");
//     ret = ft_printf("Hex: %x\n", 0);
//     printf("Return value: %d\n\n", ret);

//     // %x with large number
//     printf("16. %%x with large number:\n");
//     ret = ft_printf("Hex: %x\n", 4294967295U);
//     printf("Return value: %d\n\n", ret);

//     // %X with positive hex
//     printf("17. %%X with positive hex:\n");
//     ret = ft_printf("Hex: %X\n", 255);
//     printf("Return value: %d\n\n", ret);

//     // %X with zero
//     printf("18. %%X with zero:\n");
//     ret = ft_printf("Hex: %X\n", 0);
//     printf("Return value: %d\n\n", ret);

//     // %X with large number
//     printf("19. %%X with large number:\n");
//     ret = ft_printf("Hex: %X\n", 4294967295U);
//     printf("Return value: %d\n\n", ret);

//     // %p with normal pointer
//     printf("20. %%p with normal pointer:\n");
//     ret = ft_printf("Pointer: %p\n", ptr);
//     printf("Return value: %d\n\n", ret);

//     // %p with NULL pointer
//     printf("21. %%p with NULL pointer:\n");
//     ret = ft_printf("Pointer: %p\n", null_ptr);
//     printf("Return value: %d\n\n", ret);

//     // %% percent
//     printf("22. %%%% percent:\n");
//     ret = ft_printf("Percent: %%\n");
//     printf("Return value: %d\n\n", ret);

//     // Combination of multiple specifiers
//     printf("23. Combination:\n");
//     ret = ft_printf("%s %d %x %p %%\n", str, -42, 255, ptr);
//     printf("Return value: %d\n\n", ret);

//     // Empty format string
//     printf("24. Empty format string:\n");
//     ret = ft_printf("");
//     printf("Return value: %d\n\n", ret);

//
// Only percent without specifier (should not crash,but undefined behavior)
//     printf("25. Only percent without specifier:\n");
//     ret = ft_printf("%");
//     printf("Return value: %d\n\n", ret);

//     // Multiple percents
//     printf("26. Multiple percents:\n");
//     ret = ft_printf("%% %% %%\n");
//     printf("Return value: %d\n\n", ret);

//     // Large string
//     printf("27. Large string:\n");
//     char large_str[1001];
//     for (int i = 0; i < 1000; i++) large_str[i] = 'a';
//     large_str[1000] = '\0';
//     ret = ft_printf("Large: %s\n", large_str);
//     printf("Return value: %d\n\n", ret);

//     printf("All tests completed.\n");
//     return (0);
// }
