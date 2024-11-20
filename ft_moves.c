/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:21:20 by astefane          #+#    #+#             */
/*   Updated: 2024/11/20 13:43:18 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_and_move_max(t_stack *stack_src, t_stack *stack_dest)
{
	int	max_value;
	int	max_index;
	int	i;

	if (stack_src->size == 0)
		return ;
	max_value = stack_src->collection[0];
	max_index = 0;
	i = 1;
	while (i < stack_src->size)
	{
		if (stack_src->collection[i] > max_value)
		{
			max_value = stack_src->collection[i];
			max_index = i;
		}
		i++;
	}
	stack_dest->collection[stack_dest->size] = max_value;
	stack_dest->size++;
	ft_remove_max_from_src(stack_src, max_index);
}


void	ft_remove_max_from_src(t_stack *stack_src, int max_index)
{
	int	i;

	i = max_index;
	while (i < stack_src->size - 1)
	{
		stack_src->collection[i] = stack_src->collection[i + 1];
		i++;
	}
	stack_src->size--;
	stack_src->collection[stack_src->size] = 0;
}

void	ft_move_max(t_stack *stack_src, t_stack *stack_dest)
{
	while (stack_src->size > 0)
	{
		ft_find_and_move_max(stack_src, stack_dest);
		printf("stack_a después de mover el máximo:\n");
		ft_insert_number(stack_src);
		printf("stack_b después de recibir el máximo:\n");
		ft_insert_number(stack_dest);
	}
}
