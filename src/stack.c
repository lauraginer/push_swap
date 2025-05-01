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
#include <stdio.h>

t_program	*create_node(int value)
{
	t_program	*node;

	node = malloc(sizeof(t_program));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 1;
	node->pos = -1;
	node->target_pos = 1;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

void	add_node(t_program **stack, t_program *new)
{
	t_program	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}
