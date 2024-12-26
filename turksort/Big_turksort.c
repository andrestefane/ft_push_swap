/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Big_turksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:24:53 by astefane          #+#    #+#             */
/*   Updated: 2024/12/26 16:44:20 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_turksort_to_b(t_stack *stack_a, t_stack *stack_b,
int min_value, int max_value)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	i;
	int	index;

	chunk_size = (max_value - min_value) / 10;
	i = 0;
	while (i < 10)
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

int	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	cost;
	int	element;
	int	i;

	i = 0;
	element = stack_a->collection[i];
	cost = case_rrarrb(stack_a, stack_b, element);
	while (i < stack_a->size)
	{
		element = stack_a->collection[i];
		if (cost > case_rarb(stack_a, stack_b, element))
			cost = case_rarb(stack_a, stack_b, element);
		if (cost > case_rrarrb(stack_a, stack_b, element))
			cost = case_rrarrb(stack_a, stack_b, element);
		if (cost > case_rarrb(stack_a, stack_b, element))
			cost = case_rarrb(stack_a, stack_b, element);
		if (cost > case_rrarb(stack_a, stack_b, element))
			cost = case_rrarb(stack_a, stack_b, element);
		i++;
	}
	return (cost);
}

int	rotate_ba(t_stack *stack_a, t_stack *stack_b)
{
	int	element;
	int	cost;
	int	i;

	i = 0;
	element = stack_b->collection[i];
	cost = case_rrarrb_a(stack_a, stack_b, element);
	while (i < stack_b->size)
	{
		element = stack_b->collection[i];
		if (cost > case_rarb_a(stack_a, stack_b, element))
			cost = case_rarb_a(stack_a, stack_b, element);
		if (cost > case_rrarrb_a(stack_a, stack_b, element))
			cost = case_rrarrb_a(stack_a, stack_b, element);
		if (cost > case_rarrb_a(stack_a, stack_b, element))
			cost = case_rarrb_a(stack_a, stack_b, element);
		if (cost > case_rrarb_a(stack_a, stack_b, element))
			cost = case_rrarb_a(stack_a, stack_b, element);
		i++;
	}
	return (cost);
}
