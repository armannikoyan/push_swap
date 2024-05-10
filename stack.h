/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:37:29 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/05 23:56:34 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_H__
# define __STACK_H__

# include <stdlib.h>
# include <libc.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct	s_node
{
	int	data;
	struct s_node	*next;
} t_node;

typedef struct
{
	t_node	*m_head;
	unsigned int	m_size;
} t_stack;

void	ft_error();

void	ft_ensure_valid_input(char **argv);
void	ft_define_stack(char **argv, t_stack *stack);

void	ft_stack_push(t_stack *stack, int data);
void	ft_stack_pop(t_stack *stack);
void	ft_stack_clear(t_stack *stack);

void	ft_tiny_sort(t_stack *stack_a);

void	ft_execute(t_stack *stack_a, t_stack *stack_b, char *name, bool print);

bool	ft_stack_empty(t_stack *stack);

char	**ft_format_argv(int argc, char **argv);

t_stack	*ft_stack_ctor();
void	ft_stack_dtor(t_stack *stack);

#endif
