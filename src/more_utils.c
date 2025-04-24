/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:28:23 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/24 19:56:17 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate_stack_a(t_program **stack_a)
{
	t_program *current;
	int	lowest_pos;
	int min_index;
	int i;
	i = 0;
	
	if (!stack_a || !*stack_a) 
        return;
	get_position(stack_a);
	current = *stack_a;
	lowest_pos = current->pos;
	min_index = current->index;
	while(current)
	{
		if(current->index < min_index) //si se encuentra un nodo menor que el primero se actualiza
		{
			min_index = current->index;
			lowest_pos = current->pos;
		}
		current = current->next;
	}
	if (check_order(*stack_a) == 0)
		return ;
	while ((*stack_a)->index != 1)
	{
		if (lowest_pos <= (ft_list_size(*stack_a) / 2))
			rotate_ra(stack_a);
		else
			reverse_rotate_rra(stack_a);
	}
	// print_stack(*stack_a);
	
/* 	while((*stack_a)->index != min_index)
		rotate_ra(stack_a);	 */
}

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
		final_moves(stack_a, stack_b, cheapest_node);
	}
	// ft_printf("------STACK A---------\n");
	// print_stack(*stack_a);
	// ft_printf("------STACK B---------\n");
	// print_stack(*stack_b);
	// exit(0);
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
