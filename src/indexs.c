/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:19:15 by lauragm           #+#    #+#             */
/*   Updated: 2025/04/15 18:52:47 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void set_index(t_program **stack)
{
	t_program *current = *stack; //nuestro nodo actual(valor)
	t_program *cursor; //nodo utilizado para comparar valores
	
	while (current)
	{
		cursor = *stack;
		while(cursor)
		{
			if (current->value > cursor->value) //si el valor actual es mayor que el nodo de cursor
			{
				current->index++;
			}
			cursor = cursor->next;
		}
		current = current->next;
	}
}
