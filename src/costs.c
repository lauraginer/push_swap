/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:54 by lauragm           #+#    #+#             */
/*   Updated: 2025/04/22 20:33:08 by lginer-m         ###   ########.fr       */
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
	current = *stack_b;
	
	while(current)
	{
		if(current->pos < middle_b)
			current->cost_b = current->pos; // rb
		else
			current->cost_b = current->pos - ft_list_size(*stack_b); // rrb (negativo)
		if(current->target_pos < middle_a)
			current->cost_a = current->target_pos; //ra
		else
			current->cost_a = current->target_pos - ft_list_size(*stack_a); // rra (negativo)

		current = current->next;
	}
}

t_program *get_lowest_cost(t_program **stack_b) //para encontrar el nodo con menos cost para mover en stack b, retorna un puntero al nodo en cuestion
{
	t_program *current;
	t_program *cheapest; //valor a retornar
	int min_cost;
	int total_cost;

	current = *stack_b;
	cheapest = current;
	min_cost = INT_MAX; //para garantizar que cualquier costo sea menor
	while(current)
	{
		total_cost = manage_numbers(current->cost_a, current->cost_b);
		if(total_cost < min_cost) //si el nodo actual es menor que min_cost, actualiza min_cost y asigna el nodo actual a cheapest
		{
			min_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return(cheapest);
}

int manage_numbers(int a, int b)
{
	if(a == 0 || b == 0)
		return(0);
	if(a < 0)
		a *= -1; //es exactamente lo mismo que a = a * -1, que viene a ser a = -a
	if(b < 0)
		b *= -1;
	return(a + b);
}
