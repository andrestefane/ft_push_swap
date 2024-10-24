/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:27:46 by astefane          #+#    #+#             */
/*   Updated: 2024/10/24 21:30:15 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_list
{
	int	*sa_swap;
	int	*sb_swap;
	int	*sp;
	int	sia;
	int	sib;
	int	sip;
	int	arc;
	int	percentage;
	int	lsp;
	int	control;
	int	cont;
	int	error;
	int	atoierror;
	int	jatoi;
	int	size_block;
	int	argmax;
	int	arguments;
}	t_list;

typedef struct s_stack
{
	int	*collection;
	int	capacity;
	int	size;
}	t_stack;

int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_check_args(int argc, char **argv);
int		ft_check_num(char *s);
#endif
