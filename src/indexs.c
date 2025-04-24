/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:19:15 by lauragm           #+#    #+#             */
/*   Updated: 2025/04/24 19:43:27 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void set_index(t_program **stack)
{
	t_program *current = *stack; //nuestro nodo actual(valor)
	t_program *cursor; //nodo utilizado para comparar valores
	
	while(current)
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
	t_program *lowest;
	int pos;
	
	lowest = *stack_a;
	current = *stack_a;
	pos = 0;
	while(current)
	{
		if(lowest->index > current->index)
		{
			pos = current->pos; //actualizamos la posicion del indice mas bajo
			lowest = current; //actualizamos lowest
		}
		current = current->next;
	}
	return(pos); //retornamos la posicion del nodo con el index mas bajo
}

void get_target_position(t_program **stack_a, t_program **stack_b)
{
	/*Regla: buscamos el elemento de A con el índice más pequeño 
	que sea mayor que el índice del elemento de B*/
	
	t_program *current_b;
	t_program *current_a;
	t_program *closest;
	
	current_b = *stack_b;
	while(current_b)
	{
		closest = NULL;
		current_a = *stack_a;
		while(current_a)
		{
			if(current_a->index > current_b->index && (!closest || current_a->index < closest->index))
				closest = current_a;
			current_a = current_a->next; //avanzamos por el stack_a
		}
		if(!closest) //si no encontramos un indice mayor, entonces guardamos el indice mas pequeño del stack a
		{
			current_a = *stack_a;
			while(current_a)
			{
				if(current_a->pos == get_lowest_index(stack_a))
					closest = current_a;
				current_a = current_a->next;
			}
		}
		if (closest)
			current_b->target_pos = closest->pos;
		current_b = current_b->next;
	}
	
}