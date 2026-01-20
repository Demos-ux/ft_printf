/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:50:00 by dsisli            #+#    #+#             */
/*   Updated: 2026/01/20 14:38:03 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void    print_result(char *desc, int ret_ft, int ret_og)
{
    if (ret_ft == ret_og)
        printf("✅ [%s] OK (ret: %d)\n", desc, ret_ft);
    else
        printf("❌ [%s] FAIL (ft: %d, og: %d)\n", desc, ret_ft, ret_og);
}

int main(void)
{
    int ret_ft, ret_og;
    char *str = "Hello";
    char *null_str = NULL;
    int num = 42;
    void *ptr = &num;

    printf("\n======== FT_PRINTF MANDATORY TESTS ========\n\n");

    // 1. %c Character
    printf("--- Test %%c ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%c", 'A'); printf("\n");
    printf("OG: "); ret_og = printf("%c", 'A'); printf("\n");
    print_result("Char 'A'", ret_ft, ret_og);
    printf("\n");

    // 2. %s String
    printf("--- Test %%s ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%s", str); printf("\n");
    printf("OG: "); ret_og = printf("%s", str); printf("\n");
    print_result("String 'Hello'", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("NULL %s", null_str); printf("\n");
    printf("OG: "); ret_og = printf("NULL %s", null_str); printf("\n");
    print_result("String NULL", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("Empty %s", ""); printf("\n");
    printf("OG: "); ret_og = printf("Empty %s", ""); printf("\n");
    print_result("String Empty", ret_ft, ret_og);
    printf("\n");

    // 3. %p Pointer
    printf("--- Test %%p ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%p", ptr); printf("\n");
    printf("OG: "); ret_og = printf("%p", ptr); printf("\n");
    print_result("Pointer &num", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%p", NULL); printf("\n");
    printf("OG: "); ret_og = printf("%p", NULL); printf("\n");
    print_result("Pointer NULL", ret_ft, ret_og);
    printf("\n");

    // 4. %d Decimal
    printf("--- Test %%d ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%d", 12345); printf("\n");
    printf("OG: "); ret_og = printf("%d", 12345); printf("\n");
    print_result("Decimal 12345", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%d", -12345); printf("\n");
    printf("OG: "); ret_og = printf("%d", -12345); printf("\n");
    print_result("Decimal -12345", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%d", INT_MIN); printf("\n");
    printf("OG: "); ret_og = printf("%d", INT_MIN); printf("\n");
    print_result("Decimal INT_MIN", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%d", INT_MAX); printf("\n");
    printf("OG: "); ret_og = printf("%d", INT_MAX); printf("\n");
    print_result("Decimal INT_MAX", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%d", 0); printf("\n");
    printf("OG: "); ret_og = printf("%d", 0); printf("\n");
    print_result("Decimal 0", ret_ft, ret_og);
    
    printf("\n");

    // 5. %i Integer
    printf("--- Test %%i ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%i", 12345); printf("\n");
    printf("OG: "); ret_og = printf("%i", 12345); printf("\n");
    print_result("Integer 12345", ret_ft, ret_og);
    printf("\n");

    // 6. %u Unsigned
    printf("--- Test %%u ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%u", 12345); printf("\n");
    printf("OG: "); ret_og = printf("%u", 12345); printf("\n");
    print_result("Unsigned 12345", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%u", -1); printf("\n");
    printf("OG: "); ret_og = printf("%u", -1); printf("\n");
    print_result("Unsigned -1", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%u", 0); printf("\n");
    printf("OG: "); ret_og = printf("%u", 0); printf("\n");
    print_result("Unsigned 0", ret_ft, ret_og);
    printf("\n");

    // 7. %x Hex Lower
    printf("--- Test %%x ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%x", 0); printf("\n");
    printf("OG: "); ret_og = printf("%x", 0); printf("\n");
    print_result("Hex 0", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%x", -1); printf("\n");
    printf("OG: "); ret_og = printf("%x", -1); printf("\n");
    print_result("Hex -1", ret_ft, ret_og);
    printf("\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%x", 0); printf("\n");
    printf("OG: "); ret_og = printf("%x", 0); printf("\n");
    print_result("Hex 0", ret_ft, ret_og);
    printf("\n");

    // 8. %X Hex Upper
    printf("--- Test %%X ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%X", 255); printf("\n");
    // 9. %% Percent
    printf("--- Test %%%% ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%%"); printf("\n");
    printf("OG: "); ret_og = printf("%%"); printf("\n");
    print_result("Percent %%", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%%c"); printf("\n");
    printf("OG: "); ret_og = printf("%%c"); printf("\n");
    print_result("Percent %%c", ret_ft, ret_og);

    printf("FT: "); fflush(stdout); ret_ft = ft_printf("%%%%%%"); printf("\n");
    printf("OG: "); ret_og = printf("%%%%%%"); printf("\n");
    print_result("Percent %%%%%%", ret_ft, ret_og);
    printf("\n");

    // 10. Mixed
    printf("--- Test Mixed ---\n");
    printf("FT: "); fflush(stdout); ret_ft = ft_printf("Char: %c, Str: %s, Int: %d", 'X', "Test", 42); printf("\n");
    printf("OG: "); ret_og = printf("Char: %c, Str: %s, Int: %d", 'X', "Test", 42); printf("\n");
    print_result("Mixed", ret_ft, ret_og);
    printf("\n");

    return (0);
}
