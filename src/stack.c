/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:10:41 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/04 20:14:03 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//funcion para crear un nuevo nodo
//funcion para añadir un nodo al final del stack
//inicializar el stack a en el main

t_program	*create_node(int value) //creamos un nuevo nodo 
{
	t_program	*node;

	node = malloc(sizeof(t_program));
	if(!node)
		return(NULL);
		node->value = value;
		node->index = -1;
		node->pos = -1;
		node->target_pos = -1;
		node->cost_a = 0;
		node->cost_b = 0;
		node->next = NULL;
		return(node);
}
void	add_node(t_program **stack, t_program *new) //añades un nodo al final del stack