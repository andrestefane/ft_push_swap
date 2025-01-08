/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:27:46 by astefane          #+#    #+#             */
/*   Updated: 2025/01/08 18:27:11 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	*collection;
	int	capacity;
	int	size;
}	t_stack;

//Creación de stack

int			ft_push(t_stack *stack, int arc, char **argv);
t_stack		*ft_create_stack_a(int argc, char **argv);
t_stack		*ft_create_stack_b(int capacity);
t_stack		*create_stack(int capacity);

//Checks
int			ft_validate_split(char **arg, char **argv, int argc);
int			ft_check_length_and_limits(char *s, int is_negative);
int			ft_check_repe(int value, char **argv, int argc);
int			calculate_total_capacity(int argc, char **argv);
int			ft_validate_args(int argc, char **argv);
int			process_arg(char *arg, int *prev_num);
int			is_sorted_arg(int argc, char **argv);
void		ft_free(t_stack *stack, int error);
int			ft_new_atoi(const char *str);
int			ft_empty(const char *str);
void		ft_freedoom(char **str);
int			ft_check_num(char *s);
void		ft_putchar(char c);
int			ft_space(int c);

//Movimientos

void		print_swap_swab(t_stack *stack_a, t_stack *stack_b);
void		rrr_rra_rrb(t_stack *stack_a, t_stack *stack_b);
void		ss_swap_ab(t_stack *stack_a, t_stack *stack_b);
void		print_rrr(t_stack *stack_a, t_stack *stack_b);
void		pa_push_a(t_stack *stack_a, t_stack *stack_b);
void		pb_push_b(t_stack *stack_a, t_stack *stack_b);
void		print_pa(t_stack *stack_a, t_stack *stack_b);
void		print_pb(t_stack *stack_a, t_stack *stack_b);
void		rr_ra_rb(t_stack *stack_a, t_stack *stack_b);
void		print_rr(t_stack *stack_a, t_stack *stack_b);
void		rra_reverse_rotate_a(t_stack *stack);
void		rrb_reverse_rotate_b(t_stack *stack);
void		ra_rotate_a(t_stack *stack);
void		rb_rotate_b(t_stack *stack);
void		sa_swap_a(t_stack *stack);
void		sb_swap_b(t_stack *stack);
void		print_rra(t_stack *stack);
void		print_rrb(t_stack *stack);
void		print_sa(t_stack *stack);
void		print_sb(t_stack *stack);
void		print_ra(t_stack *stack);
void		print_rb(t_stack *stack);

// Turk

void		turksort_to_b(t_stack *stack_a, t_stack *stack_b,
				int min_value, int max_value);
void		turksort(t_stack *stack_a, t_stack *stack_b);
void		turksort_sort_b(t_stack *stack_b, t_stack *stack_a);
void		big_turksort_to_b(t_stack *stack_a, t_stack *stack_b,
				int min_value, int max_value);

// TurkCount

int			elements_in_range(t_stack *stack, int min, int max);
int			find_next_in_rage(t_stack *stack, int min, int max);
int			find_max_index(t_stack *stack);
int			find_min_index(t_stack *stack);

// TurkSort

void		turksort_to_b_5(t_stack *stack_a, t_stack *stack_b);
void		move_index_to_top_a(t_stack *stack_a, int index);
void		move_index_to_top_b(t_stack *stack_b, int index);
void		move_min_to_top(t_stack *stack);
void		sort_stack(t_stack *stack);

//Pruebas
char		determine_best_move(t_stack *stack_a, t_stack *stack_b,
				int element, int *min_case);
int			find_place_stack_a(t_stack *stack, int c);
int			find_place_stack_b(t_stack *stack, int c);
int			find_index(t_stack *stack, int c);
int			ft_min(t_stack *stack);
int			ft_max(t_stack *stack);

//Count moves pruebas

int			case_rarb(t_stack *stack_a, t_stack *stack_b, int c);
int			case_rarb_a(t_stack *stack_a, t_stack *stack_b, int c);
int			case_rrarrb(t_stack *stack_a, t_stack *stack_b, int c);
int			case_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int c);
int			case_rarrb(t_stack *stack_a, t_stack *stack_b, int c);
int			case_rarrb_a(t_stack *stack_a, t_stack *stack_b, int c);
int			case_rrarb(t_stack *stack_a, t_stack *stack_b, int c);
int			case_rrarb_a(t_stack *stack_a, t_stack *stack_b, int c);
int			rotate_ba(t_stack *stack_a, t_stack *stack_b);
int			rotate_ab(t_stack *stack_a, t_stack *stack_b);

//pruebas moves
int			apply_rrarrb(t_stack *a, t_stack *b, int c, char ab);
int			apply_rrarb(t_stack *a, t_stack *b, int c, char ab);
int			apply_rarrb(t_stack *a, t_stack *b, int c, char ab);
int			apply_rarb(t_stack *a, t_stack *b, int c, char ab);

//sort_turk

int			checksorted(t_stack *stack_a);
void		sort_upto_3(t_stack *stack_a, t_stack *stack_b);
void		sort_b(t_stack *stack_a, t_stack *stack_b);
void		sort_a(t_stack *stack_a, t_stack *stack_b);
void		sort(t_stack *stack_a, t_stack *stack_b);
void		sort_three(t_stack *stack);

#endif