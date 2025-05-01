/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:35:50 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/30 20:50:14 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_program **stack_a, t_program **stack_b)
{
	int	size;

	size = ft_list_size(*stack_a);
	if (!stack_a)
		return ;
	else if (size == 2)
		swap_sa(*stack_a);
	else if (size == 3)
		mini_sort(stack_a);
	else if (size > 3)
		max_sort(stack_a, stack_b);
}

int	validate_list(t_program *program)
{
	if (ft_list_size(program) == 1)
	{
		free_list(program);
		return (0);
	}
	if (check_int(program) < 0)
	{
		print_error();
		free_list(program);
		return (0);
	}
	if (check_duplicate(program) < 0)
	{
		print_error();
		free_list(program);
		return (0);
	}
	if (check_order(program) == 0)
	{
		free_list(program);
		return (0);
	}
	return (1);
}

int	validate_args(char *arg, t_program **program_ptr)
{
	if (check_digit(arg) < 0)
	{
		print_error();
		return (0);
	}
	*program_ptr = string_to_list(arg);
	if (!*program_ptr)
	{
		print_error();
		return (0);
	}
	return (validate_list(*program_ptr));
}

int	main(int argc, char **argv)
{
	t_program	*program;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc > 2)
		join_args(argc, argv);
	if (!validate_args(argv[1], &program))
		return (0);
	if (!execute_push_swap(program))
		return (0);
	return (0);
}
