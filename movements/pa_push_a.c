/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:59:02 by astefane          #+#    #+#             */
/*   Updated: 2024/11/29 17:04:43 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa_push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_b->size < 1)
		return ;
	temp = stack_b->collection[0];
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->collection[i] = stack_a->collection[i - 1];
		i--;
	}
	stack_a->collection[0] = temp;
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->collection[i] = stack_b->collection[i + 1];
		i++;
	}
	stack_a->size++;
	stack_b->size--;
}

void	print_pa(t_stack *stack_a, t_stack *stack_b)
{
	pa_push_a(stack_a, stack_b);
	ft_putstr("pa\n");
}
