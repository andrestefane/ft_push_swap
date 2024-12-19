/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Big_turksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:24:53 by astefane          #+#    #+#             */
/*   Updated: 2024/12/18 17:29:18 by astefane         ###   ########.fr       */
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
