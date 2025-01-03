/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_reverse_rotate_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:55:14 by astefane          #+#    #+#             */
/*   Updated: 2024/11/29 17:12:14 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_reverse_rotate_a(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->collection[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->collection[i] = stack->collection[i - 1];
		i--;
	}
	stack->collection[0] = temp;
}

void	print_rra(t_stack *stack)
{
	rra_reverse_rotate_a(stack);
	ft_putstr("rra\n");
}
