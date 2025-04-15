/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:09:48 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/15 21:23:04 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_program *string_to_list(char *str) //retorna la **cabeza de una lista enlazada** (`t_program *head`) que se construye a partir del argumento string
{
	int i;
	char **tokens;
	t_program	*new_element; //para crear un nuevo nodo
	t_program *current;
	t_program *head = NULL;
	
	i = 0;
	tokens = ft_split(str, ' '); //divide las cadenas en subcadenas
	if(!tokens)
		return NULL;
	while(tokens[i])//itera sobre las subcadenas
	{
    	new_element = (t_program *)malloc(sizeof(t_program));
		if(!new_element)
		{
			free_list(head);
			free_tokens(tokens);
			return NULL;
		}
		new_element->value = ft_atoi(tokens[i]); //convierte la sub a entero
		new_element->next = NULL; //inicializas nuevo nodo
		if(!head)
    		head = new_element;
		else
		{
			current = head;
			while(current->next)
				current = current->next;
			current->next = new_element; //actualizas con el nuevo nodo	
		}
		i++;
	}
	free_tokens(tokens);
	return(head);
}
void	free_tokens(char **tokens)
{
	int i;
	
	i = 0;
	while(tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_list(t_program *head)
{
	t_program *temp;
    
    while(head)
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

