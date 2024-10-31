/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_fuctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:17:02 by astefane          #+#    #+#             */
/*   Updated: 2024/10/31 15:39:27 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
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
		if (n > ((long long int)INT_MAX + 1) && valorfinal == -1)
			return (ft_atoierror(n));
		if (n > INT_MAX && valorfinal == 1)
			return (ft_atoierror(n));
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

int	ft_insert_number(t_stack	*stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_putnbr(stack->collection[i]);
		ft_putchar('\n');
		i++;
	}
}
