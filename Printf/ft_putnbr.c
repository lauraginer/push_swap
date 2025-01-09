/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:06:05 by lginer-m          #+#    #+#             */
/*   Updated: 2024/06/14 19:24:55 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr((int)(n / 10));
		count += ft_print_char((char)(n % 10 + 48));
	}
	else
		count += ft_print_char((char)(n + 48));
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr((int)(n / 10));
		count += ft_print_char((char)(n % 10 + 48));
	}
	else
		count += ft_print_char((char)(n + 48));
	return (count);
}

/*
int main()
{
    ft_putnbr(12345);
    ft_print_char('\n');
    ft_putnbr(-678);
    ft_print_char('\n');
    return 0;
}*/
