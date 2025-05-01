/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:37:45 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/24 20:42:14 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_swap(t_program *head)
{
	int	tmp_value;
	int	tmp_index;

	if (head == NULL || head->next == NULL)
		return ;
	tmp_value = head->value;
	head->value = head->next->value;
	head->next->value = tmp_value;
	tmp_index = head->index;
	head->index = head->next->index;
	head->next->index = tmp_index;
}

void	swap_sa(t_program *stack_a)
{
	do_swap(stack_a);
	ft_printf("sa\n");
}

void	swap_sb(t_program *stack_b)
{
	do_swap(stack_b);
	ft_printf("sb\n");
}

void	swap_ss(t_program *stack_a, t_program *stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
	ft_printf("ss\n");
}
