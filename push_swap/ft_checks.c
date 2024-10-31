/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:38:40 by astefane          #+#    #+#             */
/*   Updated: 2024/10/31 16:32:28 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (NULL);
	if (ft_validate_args(argc, argv) == -1)
		return (NULL);
	stack_a = create_stack(argc - 1);
	if (!stack_a)
		ft_free(stack_a, 1);
	if (ft_push(stack_a, argc, argv) == -1)
		ft_free(stack_a, 1);
	ft_insert_number(stack_a);
	return (NULL);
}

t_stack	*ft_create_stack_b(int capacity)
{
	t_stack	*stack_b;

	stack_b = create_stack(capacity);
	if (!stack_b)
	{
		ft_free(stack_b, 1);
		return (NULL);
	}
	return (stack_b);
}
