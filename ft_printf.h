/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:33:54 by matlopes          #+#    #+#             */
/*   Updated: 2023/10/30 11:18:10 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_base(unsigned long n, char c);
int	ft_conversions(char str, va_list arg);
int	ft_printf(const char *str, ...);

#endif
