/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:34:21 by matlopes          #+#    #+#             */
/*   Updated: 2023/10/30 11:35:36 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (str[counter])
		ft_print_char(str[counter++]);
	return (counter);
}

int	ft_print_base(unsigned long n, char c)
{
	int	size;
	int	base;

	size = 1;
	if (c == 'p')
	{
		if (!n)
			return (ft_print_str("(nil)"));
		return (ft_print_str("0x") + ft_print_base(n, 'x'));
	}
	if (c == 'd' || c == 'i' || c == 'u')
		base = 10;
	else
		base = 16;
	if (n / base)
		size += ft_print_base(n / base, c);
	if (c == 'X')
		ft_print_char("0123456789ABCDEF"[n % base]);
	else
		ft_print_char("0123456789abcdef"[n % base]);
	return (size);
}

int	ft_conversions(char str, va_list arg)
{
	long long int	value;

	if (str == 'c')
		return (ft_print_char(va_arg(arg, int)));
	if (str == 's')
		return (ft_print_str(va_arg(arg, char *)));
	if (str == 'p')
		return (ft_print_base(va_arg(arg, unsigned long), str));
	if (str == 'd' || str == 'i')
	{
		value = va_arg(arg, int);
		if (value < 0)
			return (ft_print_char('-') + ft_print_base(-value, str));
		return (ft_print_base(value, str));
	}
	if (str == 'u' || str == 'x' || str == 'X')
		return (ft_print_base(va_arg(arg, unsigned int), str));
	if (str == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	arg;

	counter = 0;
	if (!str)
		return (-1);
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%' && (str[1] == 'c' || str[1] == 's' || str[1] == 'p'
				|| str[1] == 'd' || str[1] == 'i' || str[1] == 'u'
				|| str[1] == 'x' || str[1] == 'X' || str[1] == '%'))
			counter += ft_conversions(*++str, arg);
		else
		{
			ft_print_char(*str);
			counter++;
		}
		str++;
	}
	va_end(arg);
	return (counter);
}
