/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:46:11 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/10 21:59:04 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <limits.h>

typedef struct s_program
{
	int				value;        // El número entero que debemos ordenar
	int				index;        // Su índice en la lista de todos los valores a ordenar
	int				pos;          // Su posición actual en su pila
	int				target_pos;   // Para elementos en la pila B, la posición objetivo en la pila A donde debería estar
	int				cost_a;       // Número de acciones necesarias para rotar la pila A y llevar el elemento en target_pos a la cima
	int				cost_b;       // Número de acciones necesarias para rotar la pila B y llevar este elemento a la cima
	struct s_program	*next;        // Puntero al siguiente elemento en la lista
}	t_program;

int	check_digit(char *str);
int	check_order(t_program *head);
int	check_duplicate(t_program *head);
int	check_int(t_program *head);
t_program	*string_to_list(char *str);
void	free_tokens(char **tokens);
void	free_list(t_program *head);
void	do_push(t_program **src, t_program **dest);
void	push_pa(t_program *stack_a, t_program *stack_b);
void	push_pb(t_program *stack_a, t_program *stack_b);
void	do_swap(t_program *head);
void	swap_sb(t_program *stack_b);
void	swap_sa(t_program *stack_a);
void	swap_ss(t_program *stack_a, t_program *stack_b);
void	do_rotate(t_program **head);
void	rotate_ra(t_program **stack_a);
void	rotate_rb(t_program *stack_b);
void	rotate_rr(t_program *stack_a, t_program *stack_b);
void	do_reverse_rotate(t_program **head);
void	reverse_rotate_rra(t_program **stack_a);
void	reverse_rotate_rrb(t_program **stack_b);
void	reverse_rotate_rrr(t_program **stack_a, t_program **stack_b);
t_program	*create_node(int value);
void	add_node(t_program **stack, t_program *new);
void print_stack(t_program *stack);
int	ft_list_size(t_program *head);
void 	push_swap(t_program **stack_a);
void	mini_sort(t_program **stack_a);

#endif