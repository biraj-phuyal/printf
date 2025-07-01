/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:24:36 by biphuyal          #+#    #+#             */
/*   Updated: 2025/07/01 15:01:48 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_formater(va_list args, const char format)
{
	int length;

	length = 0;
	if (format == 'c')
		length += ft_char(va_arg(args, int));
	else if (format == 's')
		length += ft_strs(va_arg(args, char *));
	else if (format == 'p')
		length += ft_hexa_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_num(va_arg(args, long long));
	else if (format == '%')
		length += ft_char('%');
	else if (format == 'u')
		length += ft_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		length += ft_hexa_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		length += ft_hexa_upper(va_arg(args, unsigned int));
	else
		length += ft_char(format);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int i;
	int length;
	va_list args;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_formater(args, format[i + 1]);
			i++;
		}
		else
			length += ft_char(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
/* 
int main(void)
{
    int ret1, ret2;

    ret1 = ft_printf("Char: %c\n", 'A');
    ret2 = printf("Char: %c\n", 'A');
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    ret1 = ft_printf("String: %s\n", "Hello");
    ret2 = printf("String: %s\n", "Hello");
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    ret1 = ft_printf("Pointer: %p\n", (void *)0x1234);
    ret2 = printf("Pointer: %p\n", (void *)0x1234);
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    ret1 = ft_printf("Decimal: %d\n", 123);
    ret2 = printf("Decimal: %d\n", 123);
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    ret1 = ft_printf("Int: %i\n", -456);
    ret2 = printf("Int: %i\n", -456);
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    ret1 = ft_printf("Unsigned: %u\n", 4294967295u);
    ret2 = printf("Unsigned: %u\n", 4294967295u);
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    ret1 = ft_printf("Hex (lower): %x\n", 305419896);
    ret2 = printf("Hex (lower): %x\n", 305419896);
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    ret1 = ft_printf("Hex (upper): %X\n", 305419896);
    ret2 = printf("Hex (upper): %X\n", 305419896);
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    ret1 = ft_printf("Percent: %%\n");
    ret2 = printf("Percent: %%\n");
    printf("ft_printf: %d, printf: %d, %s\n", ret1, ret2, (ret1 == ret2) ? "OK" : "FAIL");

    return 0;
}
 */
