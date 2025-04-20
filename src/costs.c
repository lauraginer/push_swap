/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:54 by lauragm           #+#    #+#             */
/*   Updated: 2025/04/20 01:10:45 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//calcular el total cost para cada nodo de b y seleccionar el nodo con el menor total_cost

void calculate_costs(t_program **stack_a, t_program **stack_b)
{
	int middle_a;
	int middle_b;
	t_program *current;

	middle_a = ft_list_size(*stack_a) / 2;
	middle_b = ft_list_size(*stack_b) / 2;
	current = stack_b;
	
	while(current)
	{
		if(current->pos <= middle_b)
			current->cost_b = current->pos; // rb
		else
			current->cost_b = current->pos - ft_list_size(stack_b); // rrb (negativo)
		if(current->target_pos <= middle_a)
			current->cost_a = current->target_pos; //ra
		else
			current->cost_a = current->target_pos - ft_list_size(stack_a); // rra (negativo)

		current = current->next;
	}
}

t_program *get_lowest_cost(t_program **stack_b) //para encontrar el nodo con menos cost para mover
{
	t_program *current;
	t_program *cheapest; //valor a retornar
	int min_cost;
	int total_cost;

	current = stack_b;
	cheapest = current;
	min_cost = INT_MAX;
	while(current)
	{
		total_cost = current->cost_a + current->cost_b;
		if (current->cost_a < 0)
			cost_a = -current->cost_a;
		else
			cost_a = current->cost_a;
		if (current->cost_b < 0)
			cost_b = -current->cost_b;
		else
			cost_b = current->cost_b;
			if (total_cost < min_cost)
			{
				min_cost = total_cost;
				cheapest = current;
			}
			current = current->next;
		}
		return cheapest;
}

