/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:48:28 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/30 18:01:46 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	join_args(int argc, char **argv)
{
	char	*total;
	char	*tmp;
	int		i;

	total = ft_strdup("");
	if (!total)
		return ;
	tmp = NULL;
	i = 1;
	while (i < argc)
	{
		if (i > 1)
		{
			tmp = ft_strjoin(total, " ");
			free(total);
			total = tmp;
		}
		tmp = ft_strjoin(total, argv[i]);
		free(total);
		total = tmp;
		i++;
	}
	ft_memcpy(argv[1], total, ft_strlen(total) + 1);
	free(total);
}

t_program	*create_stack_from_list(t_program *program)
{
	t_program	*stack_a;
	t_program	*new_node;
	t_program	*temp;

	stack_a = NULL;
	while (program)
	{
		new_node = create_node(program->value);
		if (!new_node)
		{
			print_error();
			free_list(stack_a);
			free_list(program);
			return (NULL);
		}
		add_node(&stack_a, new_node);
		temp = program;
		program = program->next;
		free(temp);
	}
	return (stack_a);
}

int	execute_push_swap(t_program *program)
{
	t_program	*stack_a;
	t_program	*stack_b;

	stack_b = NULL;
	stack_a = create_stack_from_list(program);
	if (!stack_a)
		return (0);
	set_index(&stack_a);
	push_swap(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (1);
}
