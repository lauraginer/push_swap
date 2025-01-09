/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:43:19 by lginer-m          #+#    #+#             */
/*   Updated: 2024/06/18 17:27:21 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_puthex(unsigned long long nbr);
int		ft_puthex_m(unsigned long long nbr);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);

/*Al igual que en la libreria, este archivo es el encargado de incluir
todas las librerias necesarias para crear la propia biblioteca de nuestra funcion
ft_printf y por lo tanto que funcione. En este caso, incluimos las librerias
stdarg.h, unistd.h y stdlib.h. La primera es necesaria para el uso de la funcion
a_list, va_start y va_end, la segunda es necesaria para el uso de la funcion
write y la tercera es necesaria para el uso de la funcion malloc.
Es muy importante saber y comprender el etma de las va_list ya que se va a
utilizar bastante (es algo parecido como a la base del proyecto)
y tener en cuenta el subject del proyecto donde se establecen las
conversiones, ya que por cada conversion se necesita una
funcion diferente (creo). */

#endif