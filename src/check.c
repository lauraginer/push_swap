/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:27:38 by lginer-m          #+#    #+#             */
/*   Updated: 2025/01/13 21:11:48 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_int(char *str)//comprueba si todos son digitos
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
	return (0);
}

int check_order(t_program *program) //comprueba si esta ordenado HAY QUE CREAR UNA FUNCION PARA CONVERTIR Y USAR LA LISTA
{
	while(program->next != NULL)
	{
		if(program->value > program->next->value)
			return(0);
		program = program->next;
	}
	return(1);
}

//int check_duplicate(char *str)//comprueba si existen numeros duplicados



//comprueba si son int, no solamente digitos