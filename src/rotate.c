/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:30:20 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/01 19:55:45 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rotate(t_program **head)
{
	t_program *temp;
	t_program *last;
	
	if(*head == NULL || *head->next == NULL)
		return ;
	temp = *head; //guardamos primer nodo
	*head = (*head)->next; //head ahora apunta al nodo 2, se recorre la lista
	temp->next = NULL; //antiguo primer nodo apunta a NULL, guardamos y aislamos value
	
	last = *head;
	while(last->next)
	last = last->next
	
	
