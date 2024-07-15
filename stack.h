/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:37:29 by anikoyan          #+#    #+#             */
/*   Updated: 2024/07/15 12:59:24 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <libc.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	unsigned int	index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*m_head;
	unsigned int	m_size;
}	t_stack;

void	ft_error(void);

char	**ft_format_argv(int argc, char **argv);
void	ft_ensure_valid_input(char **argv);
void	ft_define_stack(char **argv, t_stack *stack);

t_stack	*ft_stack_ctor(void);
void	ft_stack_dtor(t_stack *stack);
void	ft_stack_push(t_stack *stack, int data);
void	ft_stack_pop(t_stack *stack);
void	ft_stack_sort(t_stack *stack);
void	ft_stack_index(t_stack *stack);
bool	ft_stack_sorted(t_stack *stack);
bool	ft_stack_empty(t_stack *stack);
int		ft_stack_max(t_stack *stack);
int		ft_stack_min(t_stack *stack);

void	ft_execute(t_stack *stack_a, t_stack *stack_b, char *name, bool print);

#endif
