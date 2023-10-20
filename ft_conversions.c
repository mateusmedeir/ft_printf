/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:34:13 by matlopes          #+#    #+#             */
/*   Updated: 2023/10/20 12:34:14 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(char str, va_list arg)
{
	if (str == 'c')
		return (print_char(va_arg(arg, int)));
	if (str == 's')
		return (print_str(va_arg(arg, char *)));
	if (str == 'p')
		return (print_adress_helper(va_arg(arg, unsigned long)));
	if (str == 'd' || str == 'i')
		return (print_num(va_arg(arg, int)));
	if (str == 'u')
		return (print_uns_num(va_arg(arg, unsigned int)));
	if (str == 'x' || str == 'X')
		return (print_hex(va_arg(arg, unsigned int), str));
	if (str == '%')
		return (write(1, "%", 1));
	return (0);
}
