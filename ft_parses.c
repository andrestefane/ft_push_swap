/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:57:56 by astefane          #+#    #+#             */
/*   Updated: 2024/10/24 21:39:28 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *s)
{
	int	i;
	int	j;

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

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (ft_check_num(argv[i + 1]) == -1 || *argv[i + 1] == '\0')
			return (-1);
	}
	return (0);
}

