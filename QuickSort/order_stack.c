/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:21:00 by astefane          #+#    #+#             */
/*   Updated: 2024/11/29 18:08:22 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	divide_stack(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	i;
	int	size;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		if (stack_a->collection[0] <= pivot)
			print_pb(stack_a, stack_b);
		else
			print_ra(stack_a);
		i++;
	}
}

int	partition(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	i;
	int	size;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		if (stack_a->collection[0] <= pivot)
			print_pb(stack_a, stack_b);
		else
			print_ra(stack_a);
		i++;
	}
	return (pivot);
}

void	sort_stack(t_stack *stack)
{
	if (stack->size == 2 && stack->collection[0] > stack->collection[1])
		print_sa(stack);
	else if (stack->size == 3)
	{
		if (stack->collection[0] > stack->collection[1]
			&& stack->collection[0] > stack->collection[2])
			print_ra(stack);
		else if (stack->collection[1] > stack->collection[2])
			print_rra(stack);
		if (stack->collection[0] > stack->collection[1])
			print_sa(stack);
	}
}

void	sort_stack_b(t_stack *stack)
{
	if (stack->size == 2 && stack->collection[0] > stack->collection[1])
		print_sb(stack);
	else if (stack->size == 3)
	{
		if (stack->collection[0] > stack->collection[1]
			&& stack->collection[0] > stack->collection[2])
			print_rb(stack);
		else if (stack->collection[1] > stack->collection[2])
			print_rrb(stack);
		if (stack->collection[0] > stack->collection[1])
			print_sb(stack);
	}
}

void	order_stack_b(t_stack *stack)
{
	int	size;
	int	i;
	int	j;

	size = stack->size;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (stack->collection[0] > stack->collection[1])
				print_sb(stack);
			print_rb(stack);
			j++;
		}
		print_rb(stack);
		i++;
	}
}
