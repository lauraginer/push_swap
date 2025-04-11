/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:10:44 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/11 21:07:41 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mini_sort(t_program **stack_a)
{
	int a;
	int b;
	int c;
	
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if(!stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return;
	if(a < b && b > c && a < c)
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
	/*ft_printf("MINISORT\n");
	print_stack(*stack_a);*/
}
/*1. Calcular el índice medio:
   middle_index = (número total de elementos) / 2

2. Mientras el número de elementos en A sea mayor que 3:
   - Si el índice del primer elemento en A < middle_index:
       -> Hacer 'pb' (empujarlo a B)
   - Si no:
       -> Hacer 'ra' (rotar A para poner otro número en cabeza)*/
void	max_sort(t_program **stack_a, t_program **stack_b)//modificas según el indice del primer numero en el stack a
{
	int	middle_index;
	int first; //indice del primer elemento
	
	if(!stack_a || ft_list_size(*stack_a) <= 3)
		return;
	middle_index = 0;
	first = 0;
	middle_index = ft_list_size(*stack_a) / 2;
	first = (*stack_a)->index;
	while(ft_list_size(*stack_a) > 3)
	{
		/*ft_printf("size: %d\n", ft_list_size(*stack_a));
		ft_printf("index: %d\n", first);*/
		if(first < middle_index)
			push_pb(*stack_a, *stack_b);
		else
			reverse_rotate_rra(stack_a);
	}
	mini_sort(stack_a); //ordenas los tres elementos restantes en a
	
}
//importante hacer primero los indices