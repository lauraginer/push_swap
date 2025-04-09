/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:10:44 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/09 22:35:14 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mini_sort(t_program *stack_a)
{
	int a;
	int b;
	int c;
	
	a = stack_a->value;
	b = stack_a->next->value;
	c = stack_a->next->next->value;
	if(!stack_a || !stack_a->next || !stack_a->next->next)
		return;
	if(a > b && c > a) // 1 3 2
	{
		reverse_rotate_rra(&stack_a);
		swap_sa(stack_a);
	}
	else if(a > b && b < c && a < c) // 2 1 3
		swap_sa(stack_a);
	else if(a > b && b > c && a > c) // 2 3 1
		reverse_rotate_rra(&stack_a);
	else if(a > b && b < c) // 3 1 2
		rotate_ra(stack_a);
	else if(a > b && b > c) // 3 2 1
	{
		rotate_ra(stack_a);
		swap_sa(stack_a);
	}
}