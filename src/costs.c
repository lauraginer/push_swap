/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:54 by lauragm           #+#    #+#             */
/*   Updated: 2025/04/24 20:23:35 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calculate_costs(t_program **stack_a, t_program **stack_b)
{
	int			middle_a;
	int			middle_b;
	t_program	*current;

	middle_a = ft_list_size(*stack_a) / 2;
	middle_b = ft_list_size(*stack_b) / 2;
	current = *stack_b;
	while (current)
	{
		if (current->pos <= middle_b)
			current->cost_b = current->pos;
		else
			current->cost_b = current->pos - ft_list_size(*stack_b);
		if (current->target_pos <= middle_a)
			current->cost_a = current->target_pos;
		else
			current->cost_a = current->target_pos - ft_list_size(*stack_a);
		current = current->next;
	}
}

t_program	*get_lowest_cost(t_program **stack_b)
{
	t_program	*current;
	t_program	*cheapest;
	int			min_cost;
	int			total_cost;

	current = *stack_b;
	cheapest = current;
	min_cost = INT_MAX;
	while (current)
	{
		total_cost = manage_numbers(current->cost_a, current->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

int	manage_numbers(int a, int b)
{
	if (a == 0 && b == 0)
		return (0);
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}
