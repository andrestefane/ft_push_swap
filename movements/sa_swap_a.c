/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:26:24 by astefane          #+#    #+#             */
/*   Updated: 2024/11/22 14:52:40 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_swap_a(t_stack *stack)
{
	char	*temp;

	if (stack->size < 2)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = stack->collection[0];
	stack->collection[0] = stack->collection[1];
	stack->collection[1] = temp;
}
