/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:57:56 by astefane          #+#    #+#             */
/*   Updated: 2024/11/18 16:06:31 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *s)
{
	int	i;
	int	j;

	if (!s || *s == '\0')
		return (-1);
	i = 0;
	j = 0;
	if (
		(s[j] == '-' && (s[j + 1] >= '0' && s[j + 1] <= '9'))
		|| (s[j] >= '0' && s[j] <= '9'))
	{
		i++;
		j++;
		while (s[j])
		{
			if (s[j] >= '0' && s[j] <= '9')
				i++;
			j++;
		}
	}
	if (i == ft_strlen(s))
		return (0);
	return (-1);
}

int	ft_atoierror(int n)
{
	n = 0;
	if (n == 0)
	{
		ft_putstr("Error\n");
		exit (1);
	}
	return (n);
}

int	ft_validate_args(int argc, char **argv)
{
	int		i;
	char	**arg;
	int		j;
	int		value;

	i = 1;
	while (i < argc)
	{
		arg = ft_split(argv[i], ' ');
		j = 0;
		while (arg[j])
		{
			if (ft_check_num(arg[j]) == -1 || *arg[j] == '\0')
			{
				return (-1);
			}
			value = ft_atoi(arg[j]);
			if (ft_check_repe(value, argv, argc) > 1)
			{
				ft_putstr("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}


int	ft_check_repe(int value, char **argv, int argc)
{
	int		i;
	int		j;
	int		k;
	char	**arg;

	i = 1;
	j = 0;

	while (i < argc)
	{
		arg = ft_split(argv[i], ' ');
		k = 0;
		while (arg[k])
		{
			if (ft_atoi(arg[k]) == value)
				j++;
			k++;
		}
		i++;
	}
	return (j);
}

int	ft_check_duplicate(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->collection[i] == num)
			return (1);
		i++;
	}
	return (0);
}
