/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:18:21 by astefane          #+#    #+#             */
/*   Updated: 2024/11/13 17:34:12 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_partition(t_stack *stack_a, t_stack *stack_b)
{
    int pivot = stack_a->collection[0];
    int i = 1;

    // Ensure there's enough space in stack_b
    while (i < stack_a->size)
    {
        if (stack_a->collection[i] < pivot)
        {
            if (stack_b->size >= stack_b->capacity) {
                ft_putstr("Error: Stack B overflow.\n");
                return;
            }
            stack_b->collection[stack_b->size] = stack_a->collection[i];
            stack_b->size++;
        }
        else
        {
            stack_a->collection[i - 1] = stack_a->collection[i];
        }
        i++;
    }
    stack_a->collection[stack_a->size - 1] = pivot;
    stack_a->size--;
}

void ft_quick_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 1)
        return;
    ft_partition(stack_a, stack_b);
    if (stack_a->size > 1)
        ft_quick_sort(stack_a, stack_b);
    if (stack_b->size > 1)
        ft_quick_sort(stack_b, stack_a);
}




