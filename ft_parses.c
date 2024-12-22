/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:57:56 by astefane          #+#    #+#             */
/*   Updated: 2024/12/22 15:54:18 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_length_and_limits(char *s, int is_negative)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (len > 10)
		return (-1);
	if (len == 10)
	{
		if (!is_negative && ft_strncmp(s, "2147483647", 10) > 0)
			return (-1);
		if (is_negative && ft_strncmp(s, "2147483648", 10) > 0)
			return (-1);
	}
	return (0);
}

int	ft_check_num(char *s)
{
	int	i;
	int	is_negative;

	if (!s || *s == '\0')
		return (-1);
	is_negative = 0;
	if (*s == '-' || *s == '+')
	{
		if (*(s + 1) == '\0')
			return (-1);
		if (*s == '-')
			is_negative = 1;
		s++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	return (ft_check_length_and_limits(s, is_negative));
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
		if (is_sorted_arg(argc, argv) == 1 || is_sorted_arg(argc, argv) == -1)
		{
			ft_freedoom(arg);
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
