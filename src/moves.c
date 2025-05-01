/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:10:44 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/28 12:19:30 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mini_sort(t_program **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a < b && b > c && a < c)
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
}

void	max_sort(t_program **stack_a, t_program **stack_b)
{
	int	middle_index;
	int	len;
	int	i;

	len = ft_list_size(*stack_a);
	i = 0;
	if (!stack_a || !(*stack_a) || ft_list_size(*stack_a) <= 3)
		return ;
	middle_index = ft_list_size(*stack_a) / 2;
	while (i < len)
	{
		if ((*stack_a)->index <= middle_index)
			push_pb(stack_a, stack_b);
		else
			rotate_ra(stack_a);
		i++;
	}
	while (ft_list_size(*stack_a) > 3)
	{
		push_pb(stack_a, stack_b);
	}
	mini_sort(stack_a);
	final_loop(stack_a, stack_b);
	rotate_stack_a(stack_a);
}
