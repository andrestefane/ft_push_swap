/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:29:32 by astefane          #+#    #+#             */
/*   Updated: 2024/11/22 15:39:03 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb_push_b(t_stack *stack_a, t_stack *stack_b)
{
	char	*temp;
	int		i;

	if (stack_a->size < 1)
	{
		ft_putstr("Error\n");
		return ;
	}
	i = 0;
	temp = stack_a->collection[0];
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->collection[i] = stack_b->collection[i - 1];
		i--;
	}
	stack_b->collection[0] = temp;
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->collection[i] = stack_a->collection[i + 1];
		i++;
	}
	stack_b->size++;
	stack_a->size--;
}
