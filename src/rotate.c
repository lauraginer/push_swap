/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:30:20 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/28 12:17:19 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rotate(t_program **head)
{
	t_program	*first_node;
	t_program	*last_node;

	first_node = *head;
	last_node = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = first_node;
	*head = (*head)->next;
	first_node->next = NULL;
}

void	rotate_ra(t_program **stack_a)
{
	do_rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_rb(t_program **stack_b)
{
	do_rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_rr(t_program **stack_a, t_program **stack_b)
{
	do_rotate(stack_a);
	do_rotate(stack_b);
	ft_printf("rr\n");
}
