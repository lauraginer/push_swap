/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:35:50 by lginer-m          #+#    #+#             */
/*   Updated: 2025/01/16 19:48:24 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
	t_program	*program;
	t_program	*temp;
	
	if(argc == 2)
	{
		ft_memset(&program, 0, sizeof(t_program));
		if(check_digit(argv[1]) < 0)
		{
			ft_printf("Error\n");
			return(0);
		}
		program = string_to_list(argv[1]);
		if(!program)
		{
			ft_printf("Error list\n");
			return(0);
		}
		if(check_int(program) < 0)
		{
			ft_printf("Not int\n");
			return(0);
		}
		if(check_order(program) < 0)
		{
			ft_printf("Not order\n");
			return(0);
		}
		if(check_duplicate(program) < 0)
		{
			ft_printf("Not duplicate\n");
			return(0);
		}
		while(program) //libera memoria de la lista
		{
			temp = program;
			program = program->next;
			free(temp);
		}
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	return(0);
}