/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:03:03 by astefane          #+#    #+#             */
/*   Updated: 2024/12/16 20:03:10 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack, int error)
{
	if (stack)
	{
		free(stack->collection);
		free(stack);
		exit(1);
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
	int			i;

	stack_a = ft_create_stack_a(argc, argv);
	stack_b = ft_create_stack_b(stack_a->capacity);
	turksort(stack_a, stack_b);
	i = 0;
	while (i < stack_a->size)
	{
		printf("%d ", stack_a->collection[i]);
		i++;
	}
	ft_free(stack_a, 0);
	ft_free(stack_b, 0);
	return (0);
}
