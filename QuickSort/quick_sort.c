/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:46:32 by astefane          #+#    #+#             */
/*   Updated: 2024/11/29 18:10:55 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quicksort_recursive(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	get_partition;

	get_partition = partition(stack_a, stack_b, pivot);
	if (stack_a->size < 1)
		quicksort_recursive(stack_a, stack_b, pivot);
	if (stack_b->size <= 3)
		sort_stack_b(stack_b);
	else
		order_stack_b(stack_b);
	while (stack_b->size > 0)
	{
		print_pa(stack_a, stack_b);
		if (stack_a->collection[0] > stack_a->collection[1])
			print_sa(stack_a);
	}
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;

	pivot = stack_a->collection[stack_a->size / 2];
	if (stack_a->size <= 1)
		return ;
	if (stack_a->size <= 3)
	{
		sort_stack(stack_a);
		return ;
	}
	if (stack_a->size <= 9)
	{
		divide_stack(stack_a, stack_b, pivot);
		partition(stack_a, stack_b, pivot);
		while (stack_b->size > 0)
		{
			print_pa(stack_a, stack_b);
			if (stack_a->collection[0] > stack_a->collection[1])
				print_sa(stack_a);
		}
	}
	else
		quicksort_recursive(stack_a, stack_b, pivot);
}
