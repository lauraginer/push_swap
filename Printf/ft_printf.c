/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:25:54 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/08 17:24:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	compare_type(const char *format, va_list args, int *store, int i)
{
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				*store += ft_print_char(va_arg(args, int));
			if (format[i] == 's')
				*store += ft_print_string(va_arg(args, char *));
			if (format[i] == 'p')
				*store += ft_putptr(va_arg(args, void *));
			if (format[i] == 'd' || format[i] == 'i')
				*store += ft_putnbr(va_arg(args, int));
			if (format[i] == 'u')
				*store += ft_putnbr_u(va_arg(args, unsigned int));
			if (format[i] == 'x')
				*store += ft_puthex(va_arg(args, unsigned int));
			if (format[i] == 'X')
				*store += ft_puthex_m(va_arg(args, unsigned int));
			if (format[i] == '%')
				*store += ft_print_char('%');
			continue;
		}
		*store += write (1, &(format[i]), 1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		store;

	store = 0;
	va_start(args, format);
	compare_type(format, args, &store, -1);
	va_end(args);
	return (store);
}
