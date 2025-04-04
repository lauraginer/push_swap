/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:30:20 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/04 18:13:31 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rotate(t_program **head)
{
	t_program *temp;
	t_program *last;
	
	if(*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head; //guardamos primer nodo
	*head = (*head)->next; //head ahora apunta al nodo 2, se recorre la lista
	temp->next = NULL; //antiguo primer nodo apunta a NULL, guardamos y aislamos value
	
	last = *head; //operacion similar para encontrar el ultimo nodo
	while(last->next) //mientras haya un siguiente nodo
		last = last->next;
	last->next = temp; //se hace el intercambio(se anade en que su momento fue el primer nodo)
}
void	rotate_ra(t_program *stack_a)
{
	do_rotate(&stack_a);
	ft_printf("ra\n");
}
void	rotate_rb(t_program *stack_b)
{
	do_rotate(&stack_b);
	ft_printf("rb\n");
}
void	rotate_rr(t_program *stack_a, t_program *stack_b)
{
	do_rotate(&stack_a);
	do_rotate(&stack_b);
	ft_printf("rr\n");
}
