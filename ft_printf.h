/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:33:54 by matlopes          #+#    #+#             */
/*   Updated: 2023/10/20 12:33:55 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_conversions(char str, va_list arg);
int	print_char(int c);
int	print_str(char *str);
int	print_adress_helper(unsigned long n);
int	print_adress(unsigned long n);
int	print_num(int n);
int	print_uns_num(unsigned int n);
int	print_hex(unsigned int n, char c);

#endif
