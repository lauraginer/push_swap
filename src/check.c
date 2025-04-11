/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:38 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/11 19:01:38 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_digit(char *str)//comprueba si todos son digitos
{
	int i;

	i = 0;	
	if(!str[i])
		return(-1);
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while(str[i])
	{
		if(str[i] == '-')
			i++;
		if(str[i] == '+')
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
	t_program *current;
	
	if(!head)
        return (-1); // lista vacía
	current = head;
	while(current->next) // compara cada nodo con el siguiente
 	{
		if(current->value > current->next->value)
			return (-1); //está desordenada
		current = current->next;
	}
	return(0);
}

int	check_duplicate(t_program *head)//comprueba si existen numeros duplicados
{
	t_program	*current;
	t_program	*next; //otro nodo
	
	current = head;
	while(current != NULL)//empieza recorriendo los dos primeros nodos
	{
		next = current->next;
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

