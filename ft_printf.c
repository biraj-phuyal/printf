/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:44:09 by biphuyal          #+#    #+#             */
/*   Updated: 2025/07/10 21:46:29 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formater(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_char(va_arg(args, int));
	else if (format == 's')
		length += ft_strs(va_arg(args, char *));
	else if (format == 'p')
		length += ft_hexa_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_num(va_arg(args, int));
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
	int			i;
	int			length;
	va_list		args;

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

#include <stdio.h>

int main(void)
{
    int ret1, ret2;

    ret1 = printf("1: [%%]\n");
    ret2 = ft_printf("1: [%%]\n");
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("2: [%%%%]\n");
    ret2 = ft_printf("2: [%%%%]\n");
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("3: [%%%%%%]\n");
    ret2 = ft_printf("3: [%%%%%%]\n");
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("4: [%%%%%%]\n");
    ret2 = ft_printf("4: [%%%%%%]\n");
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("Char: [%c]\n", 'A');
    ret2 = ft_printf("Char: [%c]\n", 'A');
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("String: [%s]\n", "Hello");
    ret2 = ft_printf("String: [%s]\n", "Hello");
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("NULL string: [%s]\n", (char *)NULL);
    ret2 = ft_printf("NULL string: [%s]\n", (char *)NULL);
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("Pointer: [%p]\n", (void *)0x1234abcd);
    ret2 = ft_printf("Pointer: [%p]\n", (void *)0x1234abcd);
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("Decimal: [%d]\n", 123);
    ret2 = ft_printf("Decimal: [%d]\n", 123);
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("Int: [%i]\n", -456);
    ret2 = ft_printf("Int: [%i]\n", -456);
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("Unsigned: [%u]\n", 3000000000U);
    ret2 = ft_printf("Unsigned: [%u]\n", 3000000000U);
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("Hex (lower): [%x]\n", 0xdeadbeef);
    ret2 = ft_printf("Hex (lower): [%x]\n", 0xdeadbeef);
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    ret1 = printf("Hex (upper): [%X]\n", 4294967295);
    ret2 = ft_printf("Hex (upper): [%X]\n", 4294967295);
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);


    ret1 = printf("Mix: %c %s %p %d %u %x %%\n", 'Z', "42", (void *)42, -42, 42U, 42);
    ret2 = ft_printf("Mix: %c %s %p %d %u %x %%\n", 'Z', "42", (void *)42, -42, 42U, 42);
    printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

    return 0;
}
