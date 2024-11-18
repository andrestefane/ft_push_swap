/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:38:40 by astefane          #+#    #+#             */
/*   Updated: 2024/11/18 15:11:40 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (NULL);
	if (ft_validate_args(argc, argv) == -1)
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	stack_a = create_stack(argc - 1);
	if (!stack_a)
		ft_free(stack_a, 1);
	if (ft_push(stack_a, argc, argv) == -1)
		ft_free(stack_a, 1);
	/* ft_insert_number(stack_a); */
	return (stack_a);
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

void	ft_find_and_move_max(t_stack *stack_src, t_stack *stack_dest)
{
	int	max_value;
	int	max_index;
	int	i;

	if (stack_src->size == 0)
		return ;
	max_value = stack_src->collection[0];
	max_index = 0;
	i = 1;
	while (i < stack_src->size)
	{
		if (stack_src->collection[i] > max_value)
		{
			max_value = stack_src->collection[i];
			max_index = i;
		}
		i++;
	}
	if (stack_dest->size < stack_dest->capacity)
	{
		stack_dest->collection[stack_dest->size] = max_value;
		stack_dest->size++;
	}
	ft_remove_max_from_src(stack_src, max_index);
}


void	ft_remove_max_from_src(t_stack *stack_src, int max_index)
{
	int	i;

	i = max_index;
	while (i < stack_src->size - 1)
	{
		stack_src->collection[i] = stack_src->collection[i + 1];
		i++;
	}
	stack_src->size--;
	stack_src->collection[stack_src->size] = 0;
}

void	ft_move_max(t_stack *stack_src, t_stack *stack_dest)
{
	while (stack_src->size > 0)
	{
		ft_find_and_move_max(stack_src, stack_dest);
		printf("stack_a después de mover el máximo:\n");
		ft_insert_number(stack_src);
		printf("stack_b después de recibir el máximo:\n");
		ft_insert_number(stack_dest);
	}
}



