/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_reverse_rotate_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:03:26 by astefane          #+#    #+#             */
/*   Updated: 2024/11/29 17:13:15 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb_reverse_rotate_b(t_stack *stack)
{
	int		temp;
	int		i;

	temp = stack->collection[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->collection[i] = stack->collection[i - 1];
		i--;
	}
	stack->collection[0] = temp;
}

void	print_rrb(t_stack *stack)
{
	rrb_reverse_rotate_b(stack);
	ft_putstr("rrb\n");
}
