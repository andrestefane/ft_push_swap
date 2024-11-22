/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:52:47 by astefane          #+#    #+#             */
/*   Updated: 2024/11/22 15:54:01 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr_ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	ra_rotate_a(stack_a);
	rb_rotate_b(stack_b);
}
