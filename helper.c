/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:24:44 by biphuyal          #+#    #+#             */
/*   Updated: 2025/07/09 19:37:02 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_lower(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_hexa_lower(n / 16);
	count += ft_char("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_hexa_upper(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_hexa_upper(n / 16);
	count += ft_char("0123456789ABCDEF"[n % 16]);
	return (count);
}

int	ft_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned(n / 10);
	count += ft_char(n % 10 + '0');
	return (count);
}

int	ft_num(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	if (n < 0)
	{
		count += ft_char('-');
		n *= -1;
	}
	if (n >= 10)
		count += ft_num(n / 10);
	count += ft_char(n % 10 + '0');
	return (count);
}
