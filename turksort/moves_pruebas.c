/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_pruebas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:55:55 by astefane          #+#    #+#             */
/*   Updated: 2024/12/26 14:19:36 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	apply_rarb(t_stack *a, t_stack *b, int c, char ab)
{
	if (ab == 'a')
	{
		while (a->collection[0] != c && find_place_stack_b(b, c) > 0)
			print_rr(a, b);
		while (a->collection[0] != c)
			print_ra(a);
		while (find_place_stack_b(b, c) > 0)
			print_rb(b);
		print_pb(a, b);
	}
	else
	{
		while (b->collection[0] != c && find_place_stack_a(a, c) > 0)
			print_rr(a, b);
		while (b->collection[0] != c)
			print_rb(b);
		while (find_place_stack_a(a, c) > 0)
			print_ra(a);
		print_pa(a, b);
	}
	return (-1);
}

int	apply_rrarrb(t_stack *a, t_stack *b, int c, char ab)
{
	if (ab == 'a')
	{
		while (a->collection[0] != c && find_place_stack_b(b, c) > 0)
			print_rrr(a, b);
		while (a->collection[0] != c)
			print_rra(a);
		while (find_place_stack_b(b, c) > 0)
			print_rrb(b);
		print_pb(a, b);
	}
	else
	{
		while (b->collection[0] != c && find_place_stack_a(a, c) > 0)
			print_rrr(a, b);
		while (b->collection[0] != c)
			print_rrb(b);
		while (find_place_stack_a(a, c) > 0)
			print_rra(a);
		print_pa(a, b);
	}
	return (-1);
}

int	apply_rrarb(t_stack *a, t_stack *b, int c, char ab)
{
	if (ab == 'a')
	{
		while (a->collection[0] != c)
			print_rra(a);
		while (find_place_stack_b(b, c) > 0)
			print_rb(b);
		print_pb(a, b);
	}
	else
	{
		while (find_place_stack_a(a, c) > 0)
			print_rra(a);
		while (b->collection[0] != c)
			print_rb(b);
		print_pa(a, b);
	}
	return (-1);
}

int	apply_rarrb(t_stack *a, t_stack *b, int c, char ab)
{
	if (ab == 'a')
	{
		while (a->collection[0] != c)
			print_ra(a);
		while (find_place_stack_b(b, c) > 0)
			print_rrb(b);
		print_pb(a, b);
	}
	else
	{
		while (find_place_stack_a(a, c) > 0)
			print_ra(a);
		while (b->collection[0] != c)
			print_rrb(b);
		print_pa(a, b);
	}
	return (-1);
}
