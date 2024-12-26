/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pruebas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:07:42 by astefane          #+#    #+#             */
/*   Updated: 2024/12/26 12:52:09 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index(t_stack *stack, int c)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->collection[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_min(t_stack *stack)
{
	int	i;
	int	min_value;

	min_value = stack->collection[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] < min_value)
			min_value = stack->collection[i];
		i++;
	}
	return (min_value);
}

int	ft_max(t_stack *stack)
{
	int	i;
	int	max_value;

	max_value = stack->collection[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] > max_value)
			max_value = stack->collection[i];
		i++;
	}
	return (max_value);
}

int	find_place_stack_a(t_stack *stack, int c)
{
	int	i;

	if (c < ft_min(stack) || c > ft_max(stack))
		return (find_index(stack, ft_min(stack)));
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->collection[i] < c && stack->collection[i + 1] > c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	find_place_stack_b(t_stack *stack, int c)
{
	int	i;

	if (c > ft_max(stack) || c < ft_min(stack))
		return (find_index(stack, ft_max(stack)));
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->collection[i] > c && stack->collection[i + 1] < c)
			return (i + 1);
		i++;
	}
	return (0);
}
