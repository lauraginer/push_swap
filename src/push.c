/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:12:47 by lginer-m          #+#    #+#             */
/*   Updated: 2025/01/15 19:27:46 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_push(t_program *src, t_program *dest)
{
	int	tmp;

	if(src == NULL)
		return ;
	tmp = src->next; //se guarda el siguiente nodo de src
	src->next = dest; //coloca src al frente de dest
	dest = src; //se actualiza dest para src
	src = tmp; //se actualiza src para el siguiente nodo
}
void	push_pa(t_program *stack_a, t_program *stack_b)
{
	do_push(stack_b, stack_a);
	ft_printf("pa\n");
}
void	push_pb(t_program *stack_a, t_program *stack_b)
{
	do_push(stack_a, stack_b);
	ft_printf("pb\n");
}
