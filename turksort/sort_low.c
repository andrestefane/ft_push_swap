/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:35:04 by astefane          #+#    #+#             */
/*   Updated: 2024/12/16 20:05:02 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	divide_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	pivot;
	int	smallest;

	change_pivot(stack_a, &pivot);
	smallest = stack_a->collection[find_smallest(stack_a)];
	size = stack_a->size;
	while (size)
	{
		if (stack_a->collection[stack_a->size - 1] < 0)
			print_rra(stack_a);
		if (stack_a->collection[0] < pivot
			&& (stack_a->collection[0] == smallest
				|| stack_a->collection[0] < 0))
		{
			print_pb(stack_a, stack_b);
			smallest = stack_a->collection[find_smallest(stack_a)];
		}
		else
			print_ra(stack_a);
		if (stack_a->size == 3)
			break ;
	}
}

void	divide_negatives(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	pivot;
	int	smallest;

	change_pivot(stack_a, &pivot);
	smallest = stack_a->collection[find_smallest(stack_a)];
	size = stack_a->size;
	while (size)
	{
		if (stack_a->collection[0] < pivot
			&& stack_a->collection[0] == smallest)
		{
			print_pb(stack_a, stack_b);
			smallest = stack_a->collection[find_smallest(stack_a)];
		}
		else
			print_ra(stack_a);
		if (stack_a->size == 3)
			break ;
	}
}

void	order_stack_b(t_stack *stack_b, t_stack *stack_a)
{
	int	i;
	int	is_bigger;

	while (stack_b->size > 0)
	{
		i = 1;
		is_bigger = 1;
		while (i < stack_b->size)
		{
			if (stack_b->collection[0] < stack_b->collection[i])
			{
				is_bigger = 0;
				break ;
			}
			i++;
		}
		if (is_bigger)
			print_pa(stack_a, stack_b);
		else
			print_rb(stack_b);
	}
}

int	find_smallest(t_stack *stack)
{
	int	smallest;
	int	index;
	int	i;

	smallest = stack->collection[0];
	index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] < smallest)
		{
			smallest = stack->collection[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	count_negatives(t_stack *stack)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->collection[i] < 0)
			count++;
		i++;
	}
	return (count);
}
