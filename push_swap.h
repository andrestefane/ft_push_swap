/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:27:46 by astefane          #+#    #+#             */
/*   Updated: 2024/12/16 19:38:46 by astefane         ###   ########.fr       */
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
int			ft_check_repe(int value, char **argv, int argc);
int			ft_validate_args(int argc, char **argv);
int			process_arg(char *arg, int *prev_num);
int			is_sorted_arg(int argc, char **argv);
void		ft_free(t_stack *stack, int error);
int			ft_new_atoi(const char *str);
void		ft_freedoom(char **str);
int			ft_check_num(char *s);
int			ft_atoierror(int n);
void		ft_putchar(char c);
void		ft_putnbr(int n);

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

// TurkCount

int			elements_in_range(t_stack *stack, int min, int max);
int			find_next_in_rage(t_stack *stack, int min, int max);
int			find_cheap_index(t_stack *stack, int min, int max);
void		size_5(t_stack *stack_a, t_stack *stack_b);
int			calculate_moves(t_stack *stack, int index);
void		change_pivot(t_stack *stack, int *pivot);
int			get_position(t_stack *stack, int index);
int			count_negatives(t_stack *stack);
int			find_max_index(t_stack *stack);
int			find_min_index(t_stack *stack);
int			find_smallest(t_stack *stack);
int			is_sorted(t_stack *stack);

// TurkSort

void		divide_negatives(t_stack *stack_a, t_stack *stack_b);
void		order_stack_b(t_stack *stack_b, t_stack *stack_a);
void		divide_stack(t_stack *stack_a, t_stack *stack_b);
void		move_index_to_top_a(t_stack *stack, int index);
void		move_index_to_top_b(t_stack *stack, int index);
void		move_min_to_top(t_stack *stack);
void		sort_stack(t_stack *stack);

//Big_turksort

void		big_turksort_to_b(t_stack *stack_a, t_stack *stack_b,
				int min_value, int max_value);

/* //Quicksort
void		sort_stack(t_stack *stack);
void		quicksort(t_stack *stack_a, t_stack *stack_b);
void		order_stack_b(t_stack *stack_a, t_stack *stack_b);
void		divide_stack(t_stack *stack_a, t_stack *stack_b);
void		divide_negatives(t_stack *stack_a, t_stack *stack_b);
void		sort_stack_b(t_stack *stack);
int			count_negatives(t_stack *stack);
void		change_pivot(t_stack *stack, int *pivot);
int			find_smallest(t_stack *stack);

//Long_Quicksort
void		order_long_stack_b(t_stack *stack_b, t_stack *stack_a);
void		quicksort_long_numbers(t_stack *stack_a, t_stack *stack_b);
void		find_half(int *array, int size, int *small);
void		sort_array(int *array, int size);
void		move_half(t_stack *stack_a, t_stack *stack_b);
int			is_in_small(int num, int *small);
int			is_sorted_desc(t_stack *stack);
int			find_largest_index(t_stack *stack, int limit); */

#endif