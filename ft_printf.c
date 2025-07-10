/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:44:09 by biphuyal          #+#    #+#             */
/*   Updated: 2025/07/10 11:44:11 by biphuyal         ###   ########.fr       */
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
