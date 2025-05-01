/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:09:48 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/29 19:09:40 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_element_to_list(t_program **head, int value)
{
	t_program	*new_element;
	t_program	*current;

	new_element = (t_program *)malloc(sizeof(t_program));
	if (!new_element)
		return ;
	new_element->value = value;
	new_element->next = NULL;
	if (!*head)
		*head = new_element;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_element;
	}
}

t_program	*string_to_list(char *str)
{
	int			i;
	char		**tokens;
	t_program	*head;

	head = NULL;
	i = 0;
	tokens = ft_split(str, ' ');
	if (!tokens)
		return (NULL);
	while (tokens[i])
	{
		add_element_to_list(&head, ft_atoi(tokens[i]));
		if (!head)
		{
			free_tokens(tokens);
			return (NULL);
		}
		i++;
	}
	free_tokens(tokens);
	return (head);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_list(t_program *head)
{
	t_program	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	ft_list_size(t_program *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
