/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:28:23 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/22 23:02:29 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate_stack_a(t_program **stack_a);
void final_loop(t_program **stack_a, t_program **stack_b)
{
	t_program *cheapest_node;
	
	while(*stack_b)
	{
		get_position(stack_a);
		get_position(stack_b);
		get_target_position(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
		cheapest_node = get_lowest_cost(stack_b);
		final_moves(stack_a, stack_b,cheapest_node);
	}
}
void final_moves(t_program **stack_a, t_program **stack_b, t_program *cheapest_node)
{
	int cost_a;
	int cost_b;

	cost_a = cheapest_node->cost_a;
	cost_b = cheapest_node->cost_b;
	while(cost_a > 0 && cost_b > 0)
	{
		rotate_rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while(cost_a < 0 && cost_b < 0)
	{
		reverse_rotate_rrr(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	single_moves(stack_a, stack_b, cost_a, cost_b);
	push_pa(stack_a, stack_b);
}

void single_moves(t_program **stack_a, t_program **stack_b, int ca, int cb)
{
	while(ca > 0)
	{
		rotate_ra(stack_a);
		ca--;
	}
	while(ca < 0)
	{
		reverse_rotate_rra(stack_a);
		ca++;
	}
	while(cb > 0)
	{
		rotate_rb(stack_b);
		cb--;
	}
	while(cb < 0)
	{
		reverse_rotate_rrb(stack_b);
		cb++;
	}
}
