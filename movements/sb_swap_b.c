/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:09:40 by astefane          #+#    #+#             */
/*   Updated: 2024/12/06 13:53:32 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb_swap_b(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = stack->collection[0];
	stack->collection[0] = stack->collection[1];
	stack->collection[1] = temp;
}

void	print_sb(t_stack *stack)
{
	sb_swap_b(stack);
	ft_putstr("sb\n");
}
