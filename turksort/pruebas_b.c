/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:08:13 by astefane          #+#    #+#             */
/*   Updated: 2024/12/26 16:15:35 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	case_rarb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i_a;
	int	i_b;

	i_a = find_index(stack_a, c);
	i_b = find_place_stack_b(stack_b, c);
	if (i_a > i_b)
		return (i_a);
	else
		return (i_b);
}

int	case_rrarrb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i_a;
	int	i_b;

	i_a = stack_a->size - find_index(stack_a, c);
	i_b = stack_b->size - find_place_stack_b(stack_b, c);
	if (i_a > i_b)
		return (i_a);
	else
		return (i_b);
}

int	case_rarrb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i_a;
	int	i_b;

	i_a = find_index(stack_a, c);
	i_b = stack_b->size - find_place_stack_b(stack_b, c);
	return (i_a + i_b);
}

int	case_rrarb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i_a;
	int	i_b;

	i_a = stack_a->size - find_index(stack_a, c);
	i_b = find_place_stack_b(stack_b, c);
	return (i_a + i_b);
}
