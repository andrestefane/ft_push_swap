/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:41:15 by astefane          #+#    #+#             */
/*   Updated: 2024/12/26 17:13:50 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	turksort_to_b(t_stack *stack_a, t_stack *stack_b,
int min_value, int max_value)
{
	int		index;
	int		element;
	int		best_rotation_cost;

	while (stack_a->size > 0)
	{
		index = find_next_in_rage(stack_a, min_value, max_value);
		if (index == -1)
			break ;
		element = stack_a->collection[index];
		best_rotation_cost = rotate_ab(stack_a, stack_b);
		if (best_rotation_cost == case_rarb(stack_a, stack_b, element))
			apply_rarb(stack_a, stack_b, element, 'a');
		else if (best_rotation_cost == case_rrarrb(stack_a, stack_b, element))
			apply_rrarrb(stack_a, stack_b, element, 'a');
		else if (best_rotation_cost == case_rarrb(stack_a, stack_b, element))
			apply_rarrb(stack_a, stack_b, element, 'a');
		else if (best_rotation_cost == case_rrarb(stack_a, stack_b, element))
			apply_rrarb(stack_a, stack_b, element, 'a');
	}
	turksort_sort_b(stack_b, stack_a);
}

void	turksort_sort_b(t_stack *stack_b, t_stack *stack_a)
{
	int		index;
	int		element;
	int		best_rotation_cost;

	while (stack_b->size > 0)
	{
		index = find_max_index(stack_b);
		if (index == -1)
			break ;
		element = stack_b->collection[index];
		best_rotation_cost = rotate_ba(stack_a, stack_b);
		if (best_rotation_cost == case_rarb_a(stack_a, stack_b, element))
			apply_rarb(stack_a, stack_b, element, 'b');
		else if (best_rotation_cost == case_rrarrb_a(stack_a, stack_b, element))
			apply_rrarrb(stack_a, stack_b, element, 'b');
		else if (best_rotation_cost == case_rarrb_a(stack_a, stack_b, element))
			apply_rarrb(stack_a, stack_b, element, 'b');
		else if (best_rotation_cost == case_rrarb_a(stack_a, stack_b, element))
			apply_rrarb(stack_a, stack_b, element, 'b');
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
		turksort_to_b_5(stack_a, stack_b);
	else
	{
		turksort_to_b(stack_a, stack_b, min_value, max_value);
		turksort_sort_b(stack_b, stack_a);
	}
}

void	turksort_to_b_5(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	while (stack_b->size < 2)
	{
		index = find_min_index(stack_a);
		move_index_to_top_a(stack_a, index);
		print_pb(stack_a, stack_b);
	}
	sort_stack(stack_a);
	while (stack_b->size > 0)
		print_pa(stack_a, stack_b);
}