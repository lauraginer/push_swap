/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:35:50 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/15 21:25:16 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//static int check_all();
void push_swap(t_program **stack_a, t_program **stack_b)
{
	int size;
	
	size = ft_list_size(*stack_a);
	//ft_printf("SIZE : %d\n", size);
	if(!stack_a)
		return;
	else if(size == 2)
		swap_sa(*stack_a);
	else if(size == 3)
		mini_sort(stack_a);
	else if(size > 3)
		max_sort(stack_a, stack_b);	
	/*ft_printf("TAMAÑO %d\n",ft_list_size(*stack_a));
	ft_printf("PUSH SWAP\n");
	print_stack(*stack_a);
	exit(1);
	ft_printf("DESPUES DE PUSH SWAP\n");*/
}
int main(int argc, char **argv)
{
	t_program	*stack_a;
	t_program	*stack_b;
	t_program	*new_node;
	t_program	*program;
	t_program	*temp;
	
	stack_a = NULL;
	stack_b = NULL;
	if(argc == 2)
	{
		if(check_digit(argv[1]) < 0)
		{
			ft_printf("Error\n");
			return(0);
		}
		program = string_to_list(argv[1]);
		if(!program)
		{
			ft_printf("Error list\n");
			return(0);
		}
		if(ft_list_size(program) == 1)
		{
			ft_printf("Error(you need more numbers!)\n");
			free_list(program);
			return(0);
		}
		if(check_int(program) < 0)
		{
			ft_printf("Not int\n");
			free_list(program);
			return(0);
		}
		if(check_duplicate(program) < 0)
		{
			ft_printf("Is duplicate!!\n");
			free_list(program);
			return(0);
		}
		if(check_order(program) == 0)
		{
			ft_printf("Is order\n");
			free_list(program);
			return(0);
		}
		while(program)
		{
			new_node = create_node(program->value); //crear un nodo con el valor actual
			if(!new_node)
			{
				ft_printf("Error creating node\n");
				free_list(stack_a);
				free_list(program);
				return(0);
			}
			add_node(&stack_a, new_node);//añades el nodo a slack a
			temp = program; //para liberar el nodo actual de program //enterate bien de esto
			program = program->next;
			free(temp);
		}
		set_index(&stack_a);
		push_swap(&stack_a, &stack_b);
		print_stack(stack_a);
		print_stack(stack_b);
		free_list(stack_a);
		free_list(stack_b);
		free_list(program);	
	}
	else
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	return(0);
}
