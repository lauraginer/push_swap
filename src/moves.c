/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:10:44 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/10 22:16:08 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mini_sort(t_program **stack_a)
{
	int a;
	int b;
	int c;
	
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;

	if(!stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return;
	if(a < b && b > c && a < c)
	{
		reverse_rotate_rra(stack_a);
		swap_sa(*stack_a);
	}
	else if (a > b && a < c)
		swap_sa(*stack_a);
	else if (a < b && a > c)
		reverse_rotate_rra(stack_a);
	else if (a > b && a > c && b < c)
		rotate_ra(stack_a);
	else if (a > b && a > c && b > c)
	{
		swap_sa(*stack_a);
		reverse_rotate_rra(stack_a);
	}
	ft_printf("MINISORT\n");
	print_stack(*stack_a);
}