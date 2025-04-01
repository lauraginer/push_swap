/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:35:50 by lginer-m          #+#    #+#             */
/*   Updated: 2025/03/31 22:43:55 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int check_all();
int main(int argc, char **argv)
{
	t_program	*program;
	
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
			free_list(program);
			return(0);
		}
		if(check_duplicate(program) < 0)
		{
			ft_printf("Is duplicate!!\n");
			free_list(program);
			return(0);
		}
		if(check_order(program) < 0)
		{
			ft_printf("Not order\n");
			free_list(program);
			return(0);
		}
		free_list(program);
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	return(0);
}
