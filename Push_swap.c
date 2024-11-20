/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:03:03 by astefane          #+#    #+#             */
/*   Updated: 2024/11/20 13:18:38 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack, int error)
{
	if (stack)
	{
		free(stack->collection);
		free(stack);
	}
	if (error)
	{
		write(1, "Error\n", 7);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_create_stack_a(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = ft_create_stack_b(stack_a->capacity);
	if (!stack_b)
		return (1);
	ft_insert_number(stack_a);
	ft_move_max(stack_a, stack_b);
	ft_free(stack_a, 0);
	ft_free(stack_b, 0);
	return (0);
}
