/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:27:46 by astefane          #+#    #+#             */
/*   Updated: 2024/10/18 14:44:08 by astefane         ###   ########.fr       */
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

typedef struct ft_Stack_a
{
	int	*collection;
	int	capacity;
	int	size;
}	t_Stack_a;

typedef struct t_Stack_b
{
	int	*collection;
	int	capacity;
	int	size;
}	t_Stack_b;



#endif
