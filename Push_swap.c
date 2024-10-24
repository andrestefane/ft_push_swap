/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:03:03 by astefane          #+#    #+#             */
/*   Updated: 2024/10/24 15:45:21 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack_a *stack)
{
	if (stack)
	{
		free(stack->collection);
		free(stack);
		stack = NULL;
	}
}


t_stack_a	*create_stack_a(uintptr_t capacity)
{
	t_stack_a	*stack;

	stack = malloc(sizeof(t_stack_a));
	if (!stack)
		return (NULL);
	stack->collection = malloc(capacity * sizeof(int));
	if (!stack->collection)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

t_stack_a	*create_stack_b(uintptr_t capacity)
{
	t_stack_a	*stack;

	stack = malloc(sizeof(t_stack_a));
	if (!stack)
		return (NULL);
	stack->collection = malloc(capacity * sizeof(int));
	if (!stack->collection)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

int	ft_push(t_stack_a *stack, int n)
{
	if (stack->size >= stack->capacity)
		return (-1);
	stack->collection[stack->size] = n;
	stack->size++;
	return (0);
}

int	main(int argc,char **argv)
{
	t_stack_a	*stack;
	uintptr_t		i;
	uintptr_t		n;

	if (argc < 2)
	{
		write(1, "Incorrect arguments\n", 21);
		return (1);
	}
	stack = create_stack_a(argc - 1);
	if (!stack)
	{
		write(1, "Error to create the stack\n", 27);
		return (1);
	}
	i = 1;
	while (i < (uintptr_t)argc)
	{
		n = ft_atoi(argv[i]);
		if (ft_push(stack, n) == -1)
		{
			write(1, "Error the stack is full\n", 25);
			ft_free(stack);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		ft_putnbr(stack->collection[i]);
		write(1, "\n", 1);
		i++;
	}
	ft_free(stack);
	return (0);
}

