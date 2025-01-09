/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:46:11 by lginer-m          #+#    #+#             */
/*   Updated: 2025/01/01 23:36:23 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;        // El número entero que debemos ordenar
	int				index;        // Su índice en la lista de todos los valores a ordenar
	int				pos;          // Su posición actual en su pila
	int				target_pos;   // Para elementos en la pila B, la posición objetivo en la pila A donde debería estar
	int				cost_a;       // Número de acciones necesarias para rotar la pila A y llevar el elemento en target_pos a la cima
	int				cost_b;       // Número de acciones necesarias para rotar la pila B y llevar este elemento a la cima
	struct s_stack	*next;        // Puntero al siguiente elemento en la lista
}	t_stack;




#endif