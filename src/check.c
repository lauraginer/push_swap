/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:38 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/30 17:58:24 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (-1);
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] != ' ' && str[i] != '\0')
			return (-1);
		while (str[i] == ' ')
			i++;
	}
	return (0);
}

int	check_order(t_program *head)
{
	t_program	*current;

	if (!head)
		return (-1);
	current = head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (-1);
		current = current->next;
	}
	return (0);
}

int	check_duplicate(t_program *head)
{
	t_program	*current;
	t_program	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (current->value == next->value)
				return (-1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_int(t_program *head)
{
	t_program	*program;

	program = head;
	while (program != NULL)
	{
		if (program->value < INT_MIN || program->value > INT_MAX)
			return (-1);
		program = program->next;
	}
	return (0);
}
