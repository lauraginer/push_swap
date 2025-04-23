/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:35:50 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/23 21:47:29 by lginer-m         ###   ########.fr       */
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
	char *total;
	char *tmp;
	int i;

	total = NULL;
	tmp = NULL;
	if(argc >= 2)
	{
		i = 0;
		while (++i < argc) {
			tmp = ft_strjoin(total, " ");
			free(total);
			total = tmp;
			tmp = ft_strjoin(total, argv[i]);
			free(total);
			total = tmp;
		}
		ft_memcpy(argv[1], total, ft_strlen(total) + 1);
		free(total);
		if(check_digit(argv[1]) < 0)
		{
			write(2, "Error\n", 6);
			return(0);
		}
		program = string_to_list(argv[1]);
		if(!program)
		{
			write(2, "Error\n", 6);
			return(0);
		}
		if(ft_list_size(program) == 1)
		{
			write(2, "Error\n", 6);
			free_list(program);
			return(0);
		}
		if(check_int(program) < 0)
		{
			write(2, "Error\n", 6);
			free_list(program);
			return(0);
		}
		if(check_duplicate(program) < 0)
		{
			write(2, "Error\n", 6);
			free_list(program);
			return(0);
		}
		if(check_order(program) == 0)
		{
			free_list(program);
			return(0);
		}
		while(program)
		{
			new_node = create_node(program->value); //crear un nodo con el valor actual
			if(!new_node)
			{
				write(2, "Error\n", 6);
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
		//ft_printf("SLACK A\n");
		//print_stack(stack_a);
		//ft_printf("SLACK B\n");
		//print_stack(stack_b);
		free_list(stack_a);
		free_list(stack_b);
		free_list(program);	
	}
	else
		exit(EXIT_FAILURE); // termina el programa y devuelve un codigo de error al sistema operativo
	return(0);
}
