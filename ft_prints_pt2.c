/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:34:40 by matlopes          #+#    #+#             */
/*   Updated: 2023/10/20 12:34:42 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uns_num(unsigned int n)
{
	unsigned long int	value;
	int					counter;

	value = n;
	counter = 0;
	if (value > 9)
	{
		counter += print_uns_num(value / 10);
		counter += print_uns_num(value % 10);
	}
	else
		counter += print_char(value + '0');
	return (counter);
}

int	print_hex(unsigned int n, char c)
{
	int	size;

	size = 1;
	if (n / 16)
		size += print_hex(n / 16, c);
	if (c == 'x')
		print_char("0123456789abcdef"[n % 16]);
	else if (c == 'X')
		print_char("0123456789ABCDEF"[n % 16]);
	return (size);
}
