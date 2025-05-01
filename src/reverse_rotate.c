/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:02:41 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/28 12:18:12 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_reverse_rotate(t_program **head)
{
	t_program	*last_node;
	t_program	*second_last_node;
	t_program	*new_head;

	last_node = *head;
	second_last_node = NULL;
	new_head = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = *head;
	new_head = last_node;
	*head = new_head;
}

void	reverse_rotate_rra(t_program **stack_a)
{
	do_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_rrb(t_program **stack_b)
{
	do_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_rrr(t_program **stack_a, t_program **stack_b)
{
	do_reverse_rotate(stack_a);
	do_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
