/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:46:32 by astefane          #+#    #+#             */
/*   Updated: 2024/11/28 19:57:23 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	partition(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	i;
	int	size;

	pivot = stack_a->collection[stack_a->size - 1];
	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		if (stack_a->collection[0] < pivot)
		{
			pb_push_b(stack_a, stack_b);
		}
		else
		{
			ra_rotate_a(stack_a);
		}
		i++;
	}
	return (pivot);
}

void	quicksort_recursive(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	size;

	pivot = partition(stack_a, stack_b);
	if (stack_a->size < 1)
		quicksort_recursive(stack_a, stack_b);
	sort_stack_b(stack_b);
	size = stack_b->size;
	while (size > 0)
	{
		pa_push_a(stack_a, stack_b);
		size--;
	}

}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	if (stack_a->size <= 3)
	{
		sort_stack(stack_a);
		return ;
	}
	quicksort_recursive(stack_a, stack_b);
}

void	sort_stack(t_stack *stack)
{
	if (stack->size == 2 && stack->collection[0] > stack->collection[1])
		sa_swap_a(stack);
	else if (stack->size == 3)
	{
		if (stack->collection[0] > stack->collection[1])
			sa_swap_a(stack);
		if (stack->collection[1] > stack->collection[2])
		{
			ra_rotate_a(stack);
			sa_swap_a(stack);
			rra_reverse_rotate_a(stack);
		}
	}
}

void	sort_stack_b(t_stack *stack)
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
			if (stack->collection[0] < stack->collection[1])
				sb_swap_b(stack);
			rb_rotate_b(stack);
			j++;
		}
		rb_rotate_b(stack);
		i++;
	}
}
