/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:11:20 by anikoyan          #+#    #+#             */
/*   Updated: 2024/07/18 17:11:59 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static unsigned int	ft_stack_target(t_stack *stack)
{
	t_node			*tmp;
	unsigned int	target;

	tmp = stack->m_head;
	target = 0;
	while (tmp)
	{
		if (tmp->index == stack->m_size)
			break ;
		tmp = tmp->next;
		target++;
	}
	return (target);
}

static void	ft_butterfly_helper(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	mid;
	unsigned int	target;
	t_node			*tmp;

	while (stack_b->m_head)
	{
		mid = (stack_b->m_size) / 2;
		target = ft_stack_target(stack_b);
		tmp = stack_b->m_head;
		if (tmp->index == stack_b->m_size)
			ft_execute(stack_a, stack_b, "pa", true);
		else if (target < mid)
			ft_execute(NULL, stack_b, "rb", true);
		else if (target >= mid)
			ft_execute(NULL, stack_b, "rrb", true);
	}
}

static void	ft_butterfly_sort(t_stack *stack_a)
{
	t_stack			*stack_b;
	unsigned int	i;
	unsigned int	approximation;

	if (!stack_a)
		ft_error();
	stack_b = ft_stack_ctor();
	approximation = 0.0375 * stack_a->m_size + 11.25;
	i = 1;
	while (stack_a->m_head)
	{
		if (stack_a->m_head->index <= i && i > 2 && i++)
		{
			ft_execute(stack_a, stack_b, "pb", true);
			ft_execute(NULL, stack_b, "rb", true);
		}
		else if (stack_a->m_head->index <= i + approximation + 1 && i++)
			ft_execute(stack_a, stack_b, "pb", true);
		else
			ft_execute(stack_a, NULL, "ra", true);
	}
	ft_butterfly_helper(stack_a, stack_b);
	ft_stack_dtor(stack_b);
}
