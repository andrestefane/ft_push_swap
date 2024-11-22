/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rra_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:04:25 by astefane          #+#    #+#             */
/*   Updated: 2024/11/22 16:05:34 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr_rra_rrb(t_stack *stack_a, t_stack *stack_b)
{
	rra_reverse_rotate_a(stack_a);
	rrb_reverse_rotate_b(stack_b);
}
