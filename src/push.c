/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:12:47 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/28 12:19:01 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_push(t_program **stack_a, t_program **stack_b)
{
	t_program	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = tmp;
}

void	push_pa(t_program **stack_a, t_program **stack_b)
{
	do_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_pb(t_program **stack_a, t_program **stack_b)
{
	do_push(stack_a, stack_b);
	ft_printf("pb\n");
}
