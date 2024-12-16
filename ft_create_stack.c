/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:17:21 by astefane          #+#    #+#             */
/*   Updated: 2024/12/16 15:47:24 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack *stack, int arc, char **argv)
{
	int		i;
	int		j;
	int		n;
	char	**nums;

	i = 0;
	if (stack->size >= stack->capacity)
		return (-1);
	while (i < arc - 1)
	{
		nums = ft_split(argv[i + 1], ' ');
		j = 0;
		while (nums[j])
		{
			if (ft_check_num(nums[j]) == -1)
				return (-1);
			n = ft_new_atoi(nums[j]);
			stack->collection[stack->size] = n;
			stack->size++;
			j++;
		}
		ft_freedoom(nums);
		i++;
	}
	return (0);
}

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_free(stack, 1);
	stack->collection = malloc(capacity * sizeof(int));
	if (!stack->collection)
	{
		free(stack->collection);
		exit (1);
		ft_putstr("Error\n");
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

t_stack	*ft_create_stack_b(int capacity)
{
	t_stack	*stack_b;

	stack_b = create_stack(capacity);
	if (!stack_b)
	{
		ft_putstr("Error\n");
		ft_free(stack_b, 1);
		return (NULL);
	}
	return (stack_b);
}

t_stack	*ft_create_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		ft_free(stack_a, 0);
	if (ft_validate_args(argc, argv) == -1)
		ft_free(stack_a, 1);
	stack_a = create_stack(argc - 1);
	if (!stack_a)
		ft_free(stack_a, 1);
	if (ft_push(stack_a, argc, argv) == -1)
		ft_free(stack_a, 1);
	return (stack_a);
}
