/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rra_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:04:25 by astefane          #+#    #+#             */
/*   Updated: 2024/11/29 17:14:55 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr_rra_rrb(t_stack *stack_a, t_stack *stack_b)
{
	rra_reverse_rotate_a(stack_a);
	rrb_reverse_rotate_b(stack_b);
}

void	print_rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrr_rra_rrb(stack_a, stack_b);
	ft_putstr("rra rrb\n");
}
