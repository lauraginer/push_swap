/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:38 by lginer-m          #+#    #+#             */
/*   Updated: 2025/01/15 17:37:39 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_digit(char *str)//comprueba si todos son digitos
{
	int i;
	int start;

	i = 0;
	start = 0;	
	if(!str[i])
		return(-1);
	while(str[i])
	{
		while(str[i] == ' ')//saltas espacios iniciales
			i++;
		if(str[i] == '-')
			i++;
		if(!ft_isdigit(str[i]))//comprobamos que haya al menos un digito
			return(-1);
		while(ft_isdigit(str[i]))
			i++;
		if(str[i] != ' ' && str[i] != '\0')//Asegurarse de que el número está seguido por un espacio o final de cadena
			return (-1);
		while(str[i] == ' ')
			i++;
	}
	return(0);
}

int	check_order(t_program *head) //comprueba si esta ordenado
{
	t_program	*program;
	
	program = head;
	while(program != NULL)
	{
		if(program->value > program->next->value)
			return(-1);
		program = program->next; //avanza al siguiente nodo
	}
	return(0);
}

int	check_duplicate(t_program *head)//comprueba si existen numeros duplicados
{
	t_program	*current;
	t_program	*next; //otro nodo
	
	current = head;
	next = current->next;
	while(current->next != NULL)//empieza recorriendo los dos primeros nodos
	{
		while(next != NULL)//recorre el resto de la lista
		{
			if(current->value == next->value)
				return(-1);
			next = next->next; //avanza al siguiente nodo
		}
		current = current->next;
	}
	return(0);
}

int	check_int(t_program *head) //comprueba si son int, no solamente digitos
{
	t_program *program;
	
	program = head;
	while(program != NULL)
	{
		if(program->value < INT_MIN || program->value > INT_MAX)
			return(-1);
		program = program->next;
	}
	return(0);
}
