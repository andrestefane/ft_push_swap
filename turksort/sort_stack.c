/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:13:07 by astefane          #+#    #+#             */
/*   Updated: 2024/12/26 16:16:40 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_index_to_top_a(t_stack *stack, int index)
{
	int	i;

	i = 0;
	if (index <= stack->size / 2)
	{
		while (i < index)
		{
			print_ra(stack);
			i++;
		}
	}
	else
	{
		while (i < stack->size - index)
		{
			print_rra(stack);
			i++;
		}
	}
}

void	move_index_to_top_b(t_stack *stack, int index)
{
	int	i;

	i = 0;
	if (index <= stack->size / 2)
	{
		while (i < index)
		{
			print_rb(stack);
			i++;
		}
	}
	else
	{
		while (i < stack->size - index)
		{
			print_rrb(stack);
			i++;
		}
	}
}

void	move_min_to_top(t_stack *stack)
{
	int	min_index;

	min_index = find_min_index(stack);
	move_index_to_top_a(stack, min_index);
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

char	determine_best_move(t_stack *stack_a, t_stack *stack_b,
int element, int *min_case)
{
	int		rarb;
	int		rrarrb;
	int		rarrb;
	int		rrarb;
	char	best_move;

	rarb = case_rarb(stack_a, stack_b, element);
	rrarrb = case_rrarrb(stack_a, stack_b, element);
	rarrb = case_rarrb(stack_a, stack_b, element);
	rrarb = case_rrarb(stack_a, stack_b, element);
	*min_case = rarb;
	best_move = 'a';
	if (rrarrb < *min_case)
	{
		*min_case = rrarrb;
		best_move = 'b';
	}
	if (rarrb < *min_case)
	{
		*min_case = rarrb;
		best_move = 'c';
	}
	if (rrarb < *min_case)
	{
		*min_case = rrarb;
		best_move = 'd';
	}
	return (best_move);
}
