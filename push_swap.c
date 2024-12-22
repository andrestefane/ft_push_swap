/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:03:03 by astefane          #+#    #+#             */
/*   Updated: 2024/12/22 10:35:32 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack, int error)
{
	if (stack)
	{
		if (stack->collection)
			free(stack->collection);
		free(stack);
	}
	if (error == 1)
	{
		ft_putstr("Error\n");
		exit(1);
	}
}

void	ft_freedoom(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free (str);
	str = NULL;
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 2)
	{
		return (0);
		exit (0);
	}
	stack_a = ft_create_stack_a(argc, argv);
	if (!stack_a)
		ft_free(stack_a, 1);
	stack_b = ft_create_stack_b(stack_a->capacity);
	if (!stack_b)
		ft_free(stack_b, 1);
	turksort(stack_a, stack_b);
	ft_free(stack_a, 0);
	ft_free(stack_b, 0);
	return (0);
}
