/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:02:41 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/09 21:52:14 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_reverse_rotate(t_program **head)
{
	t_program *temp;
	t_program *prev;
	
	if(*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	prev = NULL;
	while(temp->next) //recorres hasta encontrar el último nodo
	{
		prev = temp; //penultimo nodo
		temp = temp->next;
	}
	prev->next = NULL; //aislas el último nodo
	temp->next = *head; //conectas el ultimo nodo al principio de la lista apuntando la posicion de head 
	*head = temp; //se cambia el valor real
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
