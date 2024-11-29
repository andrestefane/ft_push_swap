/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:35 by astefane          #+#    #+#             */
/*   Updated: 2024/11/29 17:07:57 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb_rotate_b(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->collection[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->collection[i] = stack->collection[i + 1];
		i++;
	}
	stack->collection[stack->size - 1] = temp;
}

void	print_rb(t_stack *stack)
{
	rb_rotate_b(stack);
	ft_putstr("rb\n");
}
