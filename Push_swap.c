/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:03:03 by astefane          #+#    #+#             */
/*   Updated: 2024/10/24 21:26:19 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack)
{
	if (stack)
	{
		free(stack->collection);
		free(stack);
		stack = NULL;
	}
	write(1, "Error\n", 7);
	exit(0);
}

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_free(stack);
		return (NULL);
	}
	stack->collection = malloc(capacity * sizeof(int));
	if (!stack->collection)
	{
		ft_free(stack);
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
		stack->collection[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	if (ft_check_args(argc, argv - 1) == -1)
		return (0);
	stack = create_stack(argc - 1);
	if ((create_stack(argc - 1)) == NULL)
		ft_free(stack);
	if (ft_push(stack, argc, argv) == -1)
	{
		ft_free(stack);
		return (0);
	}
	ft_free(stack);
	return (0);
}



