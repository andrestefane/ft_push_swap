/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:41:15 by astefane          #+#    #+#             */
/*   Updated: 2024/12/16 20:05:35 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	turksort_to_b(t_stack *stack_a, t_stack *stack_b,
int min_value, int max_value)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	i;
	int	index;

	chunk_size = (max_value - min_value) / 5;
	i = 0;
	while (i < 5)
	{
		chunk_min = min_value + i * chunk_size;
		chunk_max = min_value + (i + 1) * chunk_size;
		while (elements_in_range(stack_a, chunk_min, chunk_max))
		{
			index = find_next_in_rage(stack_a, chunk_min, chunk_max);
			move_index_to_top_a(stack_a, index);
			print_pb(stack_a, stack_b);
		}
		i++;
	}
	while (stack_a->size > 0)
	{
		move_min_to_top(stack_a);
		print_pb(stack_a, stack_b);
	}
}

void	turksort_sort_b(t_stack *stack_b, t_stack *stack_a)
{
	int	index;

	while (stack_b->size > 0)
	{
		index = find_max_index(stack_b);
		move_index_to_top_b(stack_b, index);
		print_pa(stack_a, stack_b);
	}
}

int	elements_in_range(t_stack *stack, int min, int max)
{
	return (find_next_in_rage(stack, min, max) != -1);
}

void	turksort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_value;
	int	max_value;

	min_value = stack_a->collection[find_min_index(stack_a)];
	max_value = stack_a->collection[find_max_index(stack_a)];
	if (stack_a->size <= 3)
	{
		sort_stack(stack_a);
		return ;
	}
	if (stack_a->size <= 5)
		size_5(stack_a, stack_b);
	else if (stack_a->size <= 100)
	{
		turksort_to_b(stack_a, stack_b, min_value, max_value);
		turksort_sort_b(stack_b, stack_a);
	}
	else
	{
		big_turksort_to_b(stack_a, stack_b, min_value, max_value);
		turksort_sort_b(stack_b, stack_a);
	}
}

void	size_5(t_stack *stack_a, t_stack *stack_b)
{
	int	negative;

	negative = count_negatives(stack_a);
	if (negative <= stack_a->size - negative)
	{
		divide_stack(stack_a, stack_b);
		sort_stack(stack_a);
	}
	else
	{
		divide_negatives(stack_a, stack_b);
		sort_stack(stack_a);
	}
	order_stack_b(stack_b, stack_a);
}
