/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:24:44 by biphuyal          #+#    #+#             */
/*   Updated: 2025/07/01 15:01:44 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexa_lower(unsigned int n)
{
    int count = 0;
    if (n >= 16)
        count += ft_hexa_lower(n / 16);
    count += ft_char("0123456789abcdef"[n % 16]);
    return (count);
}

int ft_hexa_upper(unsigned int n)
{
    int count = 0;
    if (n >= 16)
        count += ft_hexa_upper(n / 16);
    count += ft_char("0123456789ABCDEF"[n % 16]);
    return (count);
}

int ft_unsigned(unsigned int n)
{
    int count = 0;
    if (n >= 10)
        count += ft_unsigned(n / 10);
    count += ft_char(n % 10 + '0');
    return (count);
}

int ft_num(long long n)
{
    long long count;

    count = 0;
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
