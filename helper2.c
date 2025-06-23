/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:24:47 by biphuyal          #+#    #+#             */
/*   Updated: 2025/06/23 19:46:08 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strs(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_hexa_pointer(unsigned long long n)
{
    int count;
	
	count = 0;
    if (n == 0)
        return (write(1, "0x0", 3)); 

    count += write(1, "0x", 2);
    if (n >= 16)
        count += ft_hexa_pointer_rec(n / 16);
    count += ft_char("0123456789abcdef"[n % 16]);
    return (count);
}

int ft_hexa_pointer_rec(unsigned long long n)
{
    int count = 0;
    if (n >= 16)
        count += ft_hexa_pointer_rec(n / 16);
    count += ft_char("0123456789abcdef"[n % 16]);
    return (count);
}