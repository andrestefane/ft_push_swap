/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:03:03 by astefane          #+#    #+#             */
/*   Updated: 2024/10/31 16:34:37 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack, int error)
{
	if (stack)
	{
		free(stack->collection);
		free(stack);
		stack = NULL;
	}
	if (error)
	{
		write(1, "Error\n", 7);
		exit(1);
	}
}

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_free(stack, 1);
		return (NULL);
	}
	stack->collection = malloc(capacity * sizeof(int));
	if (!stack->collection)
	{
		ft_free(stack, 1);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

int	ft_push(t_stack *stack, int arc, char **argv)
{
	int	i;

	i = 0;
	if (stack->size >= stack->capacity)
		return (-1);
	while (i < arc - 1)
	{
		if (ft_check_num(argv[i + 1]) == -1)
			return (-1);
		stack->collection[stack->size] = ft_atoi(argv[i + 1]);
		stack->size++;
		i++;
	}
	return (0);
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
	ft_free(stack_a, 0);
	return (0);
}



