/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_fuctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:17:02 by astefane          #+#    #+#             */
/*   Updated: 2024/12/16 18:40:33 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new_atoi(const char *str)
{
	int				i;
	int				valorfinal;
	long long int	n;

	n = 0;
	i = 0;
	valorfinal = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			valorfinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
		if (n > INT_MAX || n < INT_MIN)
		{
			return (ft_atoierror(n));
		}
	}
	return (n * valorfinal);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar('-');
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar(ln + '0');
	else
	{
		ft_putnbr(ln / 10);
		ft_putnbr(ln % 10);
	}
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
		i++;
	}
	return (1);
}
