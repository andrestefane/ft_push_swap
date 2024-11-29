/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_swap_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:53:46 by astefane          #+#    #+#             */
/*   Updated: 2024/11/29 17:26:42 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss_swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 || stack_b->size < 2)
	{
		ft_putstr("Error\n");
		return ;
	}
	sa_swap_a(stack_a);
	sb_swap_b(stack_b);
}

void	print_swap_swab(t_stack *stack_a, t_stack *stack_b)
{
	ss_swap_ab(stack_a, stack_b);
	ft_putstr("swap swab\n");
}
