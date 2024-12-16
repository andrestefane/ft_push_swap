/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_numbs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:43:55 by astefane          #+#    #+#             */
/*   Updated: 2024/12/16 19:12:20 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_index(t_stack *stack)
{
	int	max_value;
	int	max_index;
	int	i;

	max_value = stack->collection[0];
	max_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] > max_value)
		{
			max_value = stack->collection[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	find_min_index(t_stack *stack)
{
	int	min_value;
	int	min_index;
	int	i;

	min_value = stack->collection[0];
	min_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] < min_value)
		{
			min_value = stack->collection[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_next_in_rage(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->collection[i] >= min && stack->collection[i] < max)
			return (i);
		i++;
	}
	return (-1);
}

void	change_pivot(t_stack *stack, int *pivot)
{
	int	new_pivot;
	int	i;

	new_pivot = stack->collection[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] > new_pivot)
			new_pivot = stack->collection[i];
		i++;
	}
	*pivot = new_pivot;
}
