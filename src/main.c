/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:35:50 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/09 22:41:01 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//static int check_all();
void push_swap(t_program *stack_a)
{
	int size;
	
	size = ft_list_size(stack_a);
	if(!stack_a)
		return;
	else if(size == 2)
		swap_sa(stack_a);
	else if(size == 3)
		mini_sort(stack_a);
		
	/*else if(size > 3)
		rest_sort(stack_a);*/
}
int main(int argc, char **argv)
{
	t_program	*stack_a;
	t_program	*stack_b;
	t_program	*new_node;
	t_program	*program;
	t_program	*temp;
	int i;
	
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if(argc == 2)
	{
		/*while(argv[i])
		{
			if(ft_strchr(argv[i], ' '))
			{
				ft_printf("Error\n");
				return(0);
			}
			i++;
		}*/
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
		push_swap(stack_a);   
		print_stack(stack_a);
		free_list(stack_a);
		free_list(program);	
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	return(0);
}
