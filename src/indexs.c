/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:19:15 by lauragm           #+#    #+#             */
/*   Updated: 2025/04/16 19:59:45 by lginer-m         ###   ########.fr       */
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
void get_position(t_program **stack)
{
	t_program *current;
	int position;
	
	current = *stack;
	position = 0;
	while(current)
	{
		current->pos = position;
		position++;
		current = current->next;
	}
}
int	get_lowest_index(t_program **stack_a)
{
	t_program *current;
	t_program *count;
	int pos;
	
	count = stack_a;
	current = *stack_a;
	pos = 0;
	while(stack_a)
}
void get_target_position(t_program **stack_a, t_program **stack_b)
{
	/*Regla: buscamos el elemento de A con el índice más pequeño 
	que sea mayor que el índice del elemento de B*/
	
	t_program *current;
	int t_pos;
	
	
	current = *stack_b;
	t_pos = 0;
	current->target_pos = t_pos;
	
}