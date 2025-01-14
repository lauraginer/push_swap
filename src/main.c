/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:35:50 by lginer-m          #+#    #+#             */
/*   Updated: 2025/01/14 20:20:01 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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