/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:34:21 by matlopes          #+#    #+#             */
/*   Updated: 2023/10/20 14:51:32 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	arg;

	counter = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%' && *str + 1)
			counter += ft_conversions(*++str, arg);
		else
		{
			write(1, &*str, 1);
			counter++;
		}
		str++;
	}
	va_end(arg);
	return (counter);
}
