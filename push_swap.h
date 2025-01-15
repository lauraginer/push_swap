/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:46:11 by lginer-m          #+#    #+#             */
/*   Updated: 2025/01/14 21:14:42 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <limits.h>

typedef struct s_program
{
	int				value;        // El número entero que debemos ordenar
	int				index;        // Su índice en la lista de todos los valores a ordenar
	int				pos;          // Su posición actual en su pila
	int				target_pos;   // Para elementos en la pila B, la posición objetivo en la pila A donde debería estar
	int				cost_a;       // Número de acciones necesarias para rotar la pila A y llevar el elemento en target_pos a la cima
	int				cost_b;       // Número de acciones necesarias para rotar la pila B y llevar este elemento a la cima
	struct s_program	*next;        // Puntero al siguiente elemento en la lista
}	t_program;

int check_digit(char *str);
int check_order(t_program *head);
int check_duplicate(t_program *head);
int check_int(t_program *head);

#endif