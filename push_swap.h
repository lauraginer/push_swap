/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:46:11 by lginer-m          #+#    #+#             */
/*   Updated: 2025/04/30 21:45:13 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <limits.h>

typedef struct s_program
{
	int					value;
	int					index;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_program	*next;
}						t_program;

/* ---------------------- CHECK.C ---------------------- */
int						check_digit(char *str);
int						check_order(t_program *head);
int						check_duplicate(t_program *head);
int						check_int(t_program *head);

/* ---------------------- COSTS.C ---------------------- */
void					calculate_costs(t_program **stack_a,
							t_program **stack_b);
int						manage_numbers(int a, int b);
t_program				*get_lowest_cost(t_program **stack_b);

/* ---------------------- FINAL_STEP.C ---------------------- */
void					final_moves(t_program **stack_a, t_program **stack_b,
							t_program *cheapest_node);
void					single_moves(t_program **stack_a, t_program **stack_b,
							int ca, int cb);
void					final_loop(t_program **stack_a, t_program **stack_b);
void					rotate_stack_a(t_program **stack_a);

/* ---------------------- INDEXS.C ---------------------- */
void					set_index(t_program **stack);
void					get_position(t_program **stack);
int						get_lowest_index(t_program **stack_a);
void					get_target_position(t_program **stack_a,
							t_program **stack_b);
void					if_closest_null(t_program **stack_a,
							t_program **closest);

/* ---------------------- MAIN.C ---------------------- */
void					push_swap(t_program **stack_a, t_program **stack_b);
void					print_error(void);
int						validate_list(t_program *program);
int						validate_args(char *arg, t_program **program_ptr);
void					join_args(int argc, char **argv);
t_program				*create_stack_from_list(t_program *program);
int						execute_push_swap(t_program *program);

/* ---------------------- MORE_UTILS.C ---------------------- */
int						find_lowest_index_position(t_program *stack);

/* ---------------------- PUSH.C ---------------------- */
void					do_push(t_program **stack_a, t_program **stack_b);
void					push_pa(t_program **stack_a, t_program **stack_b);
void					push_pb(t_program **stack_a, t_program **stack_b);

/* ---------------------- REVERSE_ROTATE.C ---------------------- */
void					do_reverse_rotate(t_program **head);
void					reverse_rotate_rra(t_program **stack_a);
void					reverse_rotate_rrb(t_program **stack_b);
void					reverse_rotate_rrr(t_program **stack_a,
							t_program **stack_b);

/* ---------------------- ROTATE.C ---------------------- */
void					do_rotate(t_program **head);
void					rotate_ra(t_program **stack_a);
void					rotate_rb(t_program **stack_b);
void					rotate_rr(t_program **stack_a, t_program **stack_b);

/* ---------------------- STACK.C ---------------------- */
t_program				*create_node(int value);
void					add_node(t_program **stack, t_program *new);
void					print_stack(t_program *stack);
int						ft_list_size(t_program *head);
void					mini_sort(t_program **stack_a);
void					max_sort(t_program **stack_a, t_program **stack_b);

/* ---------------------- SWAP.C ---------------------- */
void					do_swap(t_program *head);
void					swap_sb(t_program *stack_b);
void					swap_sa(t_program *stack_a);
void					swap_ss(t_program *stack_a, t_program *stack_b);

/* ---------------------- UTILS.C ---------------------- */
void					add_element_to_list(t_program **head, int value);
t_program				*string_to_list(char *str);
void					free_tokens(char **tokens);
void					free_list(t_program *head);

#endif