/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:10:44 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/21 22:53:14 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mini_sort(t_program **stack_a)
{
	int a;
	int b;
	int c;
	
	if(!stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
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
/*2. Mientras el número de elementos en A sea mayor que 3:
   - Si el índice del primer elemento en A < middle_index:
       -> Hacer 'pb' (empujarlo a B)
   - Si no:
       -> Hacer 'ra' (rotar A para poner otro número en cabeza)*/
void	max_sort(t_program **stack_a, t_program **stack_b)//dividimos A: si el índice es menor que la mitad, enviamos a B; si no, rotamos A 
{
	int	middle_index;
	int len = ft_list_size(*stack_a);
	int i = 0;
	
	if(!stack_a || !(*stack_a) || ft_list_size(*stack_a) <= 3)
		return;
	middle_index = ft_list_size(*stack_a) / 2;
	ft_printf("%d\n",middle_index);
	while(i < len)
	{
		if((*stack_a)->index <= middle_index)
			push_pb(stack_a, stack_b);
		else
			rotate_ra(stack_a);
		i++;
	}
	while(ft_list_size(*stack_a) > 3)
		push_pb(stack_a,stack_b);
	mini_sort(stack_a); //ordenas los tres elementos restantes en a
	get_position(stack_a);
	get_position(stack_b);
	get_target_position(stack_a, stack_b);
	calculate_costs(stack_a, stack_b);
	
}

