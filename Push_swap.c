/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:03:03 by astefane          #+#    #+#             */
/*   Updated: 2024/10/18 14:03:27 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Push_swap.h>

int	*ft_free(int **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

t_stack_a	create_stack_a(int capacity)
{
	t_stack_a	*stack;

	*stack = malloc(sizeof(t_stack_a));
	if (!*stack)
		stack = ft_free;
	stack->collection = malloc(capacity * sizeof(int));
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

t_stack_b	create_stack_b(int capacity)
{
	t_stack_b	*stack;

	*stack = malloc(sizeof(t_stack_b));
	if (!*stack)
		stack = ft_free;
	stack->collection = malloc(capacity * sizeof(int));
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}
