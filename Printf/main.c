/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:02:02 by lginer-m          #+#    #+#             */
/*   Updated: 2024/06/18 17:41:08 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/*int main()
{
	int i;
	int j;

	j = 0;
	j = 0;
	i = ft_printf("dbk%s\n", "quepasa");
	j = printf("dbk%s\n", "quepasa");
	printf("numf: %i\n", i);
	printf("numv: %i\n", j);
	return (0);
}*/

/* int	main(void)
{
	void	*ptr;
	int		k;
	int		l;

	k = 0;
	l = 0;
	ptr = malloc(1);
	k = printf ("printf originalo %p\n %p\n", (void *)3, ptr);
	l = ft_printf ("printf original %p\n %p\n", (void *)3, ptr);
	printf("memoria original: %i\n", k);
	printf("memoria mía: %i\n", l);
	return (0);
} */

int	main(void)
{
	void	*ptr;
	int		k;
	int		l;

	k = 0;
	l = 0;
	ptr = malloc(1);
	k = printf ("printf originalo %d\n %x\n", 64, 64);
	l = ft_printf ("printf mio %d\n %x\n", 64, 64);
	printf("memoria original: %i\n", k);
	printf("memoria mía: %i\n", l);
	return (0);
}

/*int	main()
{
	int	result;
	int result2;

	result = ft_printf("%x", 537);
	printf("%x", result);
	printf("\n");
	result2 = printf("%x", 106);
	printf("\n");
	printf("%X", result2);
	return (0);
}*/
