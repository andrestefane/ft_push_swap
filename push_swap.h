/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:27:46 by astefane          #+#    #+#             */
/*   Updated: 2024/11/18 11:46:26 by astefane         ###   ########.fr       */
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

int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_check_num(char *s);
int		ft_atoierror(int n);
int		ft_insert_number(t_stack	*stack);
int		ft_validate_args(int argc, char **argv);
t_stack	*ft_create_stack_a(int argc, char **argv);
int		ft_push(t_stack *stack, int arc, char **argv);
t_stack	*create_stack(int capacity);
void	ft_free(t_stack *stack, int error);
t_stack	*ft_create_stack_b(int capacity);
int		ft_check_repe(int value, char **argv, int argc);
int		ft_check_duplicate(t_stack *stack, int num);
void	ft_find_and_move_max(t_stack *stack_src, t_stack *stack_dest);
void	ft_remove_max_from_src(t_stack *stack_src, int max_index);
void	ft_move_max(t_stack *stack_src, t_stack *stack_dest);
#endif
