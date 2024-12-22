/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:17:21 by astefane          #+#    #+#             */
/*   Updated: 2024/12/19 17:40:13 by astefane         ###   ########.fr       */
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
				return (free(nums), -1);
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
		ft_free(stack, 1);
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

t_stack	*ft_create_stack_b(int capacity)
{
	t_stack	*stack_b;

	stack_b = NULL;
	stack_b = create_stack(capacity);
	if (!stack_b)
		ft_free(stack_b, 1);
	return (stack_b);
}

t_stack	*ft_create_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;
	int		total_capacity;

	stack_a = NULL;
	if (ft_validate_args(argc, argv) == -1)
		ft_free(stack_a, 1);
	total_capacity = calculate_total_capacity(argc, argv);
	stack_a = create_stack(total_capacity);
	if (!stack_a)
		ft_free(stack_a, 1);
	if (ft_push(stack_a, argc, argv) == -1)
		ft_free(stack_a, 1);
	return (stack_a);
}
