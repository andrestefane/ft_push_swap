/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:57:56 by astefane          #+#    #+#             */
/*   Updated: 2024/12/16 17:59:59 by astefane         ###   ########.fr       */
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

int	ft_validate_split(char **arg, char **argv, int argc)
{
	int	j;
	int	value;

	j = 0;
	while (arg[j])
	{
		if (ft_check_num(arg[j]) == -1 || *arg[j] == '\0')
			return (-1);
		value = ft_new_atoi(arg[j]);
		if (ft_check_repe(value, argv, argc) > 1)
			return (-1);
		j++;
	}
	return (0);
}

int	ft_validate_args(int argc, char **argv)
{
	int		i;
	char	**arg;

	i = 1;
	while (i < argc)
	{
		arg = ft_split(argv[i], ' ');
		if (!arg)
			return (-1);
		if (ft_validate_split(arg, argv, argc) == -1)
		{
			ft_freedoom(arg);
			return (-1);
		}
		if (is_sorted_arg(argc, argv) == 1)
		{
			ft_putstr("ordenado\n");
			exit (0);
		}
		ft_freedoom(arg);
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
			if (ft_new_atoi(arg[k]) == value)
				j++;
			k++;
		}
		ft_freedoom(arg);
		i++;
	}
	return (j);
}
