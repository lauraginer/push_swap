/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:35:50 by lginer-m          #+#    #+#             */
/*   Updated: 2025/01/15 21:33:37 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_program string_to_list(char *str)
{
	int i;
	char **tokens;
	t_program	*new_element;
	t_program *current;
	t_program *head = NULL;
	
	i = 0;
	tokens = ft_split(str, ' '); //divide las cadenas en subcadenas
	while(tokens[i])
	{
    	new_element = (t_program *)malloc(sizeof(t_program));
    	if (!new_element)
       		return ;
	}
	new_element->value = ft_atoi(tokens[i]);
	new_element->next = NULL; //inicializas nuevo nodo
	if (!head)
    	head = new_element;
	else
    	current->next = new_element; //actualizas con el nuevo nodo	
	current = new_element;
	i++;
}
void free_tokens(char *tokens)
{
	int i;
	
	i = 0;
	while(tokens[i])
    	free(tokens[i++]);
	free(tokens);
}

int main(int argc, char **argv)
{
	t_program	program;
	
	if(argc == 2)
	{
		ft_memset(&program, 0, sizeof(t_program));
		if(check_digit(argv[1]) < 0)
		{
			ft_printf("Error\n");
			return(1);
		}
		if(check_order(&program) < 0)
		{
			ft_printf("Not order\n");
			return(1);
		}
		if(check_int(&program) < 0)
		{
			ft_printf("Not int\n");
			return(1);
		}
		if(check_duplicate(&program) < 0)
		{
			ft_printf("Not duplicate\n");
			return(1);
		}
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	return(0);
}