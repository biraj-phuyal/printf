/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:24:41 by biphuyal          #+#    #+#             */
/*   Updated: 2025/07/09 19:49:56 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_strs(char *str);
int	ft_char(int c);
int	ft_unsigned(unsigned int n);
int	ft_num(int n);
int	ft_hexa_lower(unsigned int n);
int	ft_hexa_upper(unsigned int n);
int	ft_hexa_pointer(unsigned long long n);
int	ft_hexa_pointer_rec(unsigned long long n);

#endif