/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:19:15 by lauragm           #+#    #+#             */
/*   Updated: 2025/05/01 17:09:30 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_program **stack)
{
	t_program	*current;
	t_program	*cursor;

	current = *stack;
	while (current)
	{
		cursor = *stack;
		while (cursor)
		{
			if (current->value > cursor->value)
			{
				current->index++;
			}
			cursor = cursor->next;
		}
		current = current->next;
	}
}

void	get_position(t_program **stack)
{
	t_program	*current;
	int			position;

	current = *stack;
	position = 0;
	while (current)
	{
		current->pos = position;
		position++;
		current = current->next;
	}
}

int	get_lowest_index(t_program **stack_a)
{
	t_program	*current;
	t_program	*lowest;
	int			pos;

	lowest = *stack_a;
	current = *stack_a;
	pos = 0;
	while (current)
	{
		if (lowest->index > current->index)
		{
			pos = current->pos;
			lowest = current;
		}
		current = current->next;
	}
	return (pos);
}

void	get_target_position(t_program **stack_a, t_program **stack_b)
{
	t_program	*current_b;
	t_program	*current_a;
	t_program	*closest;

	current_b = *stack_b;
	while (current_b)
	{
		closest = NULL;
		current_a = *stack_a;
		while (current_a)
		{
			if (current_a->index > current_b->index && (!closest
					|| current_a->index < closest->index))
				closest = current_a;
			current_a = current_a->next;
		}
		if (!closest)
			if_closest_null(stack_a, &closest);
		if (closest)
			current_b->target_pos = closest->pos;
		current_b = current_b->next;
	}
}

void	if_closest_null(t_program **stack_a, t_program **closest)
{
	t_program	*current_a;

	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->pos == get_lowest_index(stack_a))
			*closest = current_a;
		current_a = current_a->next;
	}
}
