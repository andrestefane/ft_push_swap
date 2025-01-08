/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_fuctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:17:02 by astefane          #+#    #+#             */
/*   Updated: 2025/01/08 18:25:42 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	n;

	n = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
		if ((sign == 1 && n > INT_MAX)
			|| (sign == -1 && n > (long long)INT_MAX + 1))
			return (-1);
	}
	return ((int)(n * sign));
}

int	calculate_total_capacity(int argc, char **argv)
{
	int		i;
	int		total_capacity;
	char	**nums;
	int		j;

	i = 1;
	total_capacity = 0;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		j = 0;
		while (nums[j])
		{
			total_capacity++;
			j++;
		}
		ft_freedoom(nums);
		i++;
	}
	return (total_capacity);
}

int	process_arg(char *arg, int *prev_num)
{
	char	**split;
	int		j;
	int		current_num;

	split = ft_split(arg, ' ');
	j = 0;
	while (split[j])
	{
		current_num = ft_new_atoi(split[j]);
		if (*prev_num > current_num)
		{
			ft_freedoom(split);
			return (0);
		}
		*prev_num = current_num;
		j++;
	}
	ft_freedoom(split);
	return (1);
}

int	is_sorted_arg(int argc, char **argv)
{
	int	i;
	int	prev_num;

	i = 1;
	prev_num = ft_new_atoi(argv[i]);
	while (i < argc)
	{
		if (!process_arg(argv[i], &prev_num))
			return (0);
		if (ft_empty(argv[i]))
			return (2);
		i++;
	}
	return (1);
}

int	ft_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
