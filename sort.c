/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:05:49 by anikoyan          #+#    #+#             */
/*   Updated: 2024/07/15 15:28:53 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_tiny_sort(t_stack *stack)
{
	int		max;

	if (!stack)
		ft_error();
	max = ft_stack_max(stack);
	if (stack->m_head->data == max)
		ft_execute(stack, NULL, "ra", true);
	else if (stack->m_head->next->data == max)
		ft_execute(stack, NULL, "rra", true);
	if (stack->m_head->data > stack->m_head->next->data)
		ft_execute(stack, NULL, "sa", true);
}

static unsigned int	ft_iter_to_min(t_stack *stack, int min)
{
	t_node			*tmp;
	unsigned int	iter_to_min;

	tmp = stack->m_head;
	iter_to_min = 0;
	while (tmp && tmp->data != min)
	{
		tmp = tmp->next;
		iter_to_min++;
	}
	return (iter_to_min);
}

static void	ft_simple_sort(t_stack *stack_a)
{
	t_stack			*stack_b;
	int				min;
	unsigned int	iter_to_min;

	if (!stack_a)
		ft_error();
	stack_b = ft_stack_ctor();
	while (stack_a->m_size > 3)
	{
		min = ft_stack_min(stack_a);
		iter_to_min = ft_iter_to_min(stack_a, min);
		while (stack_a->m_head->data != min)
		{
			if (iter_to_min < stack_a->m_size / 2)
				ft_execute(stack_a, NULL, "ra", true);
			else
				ft_execute(stack_a, NULL, "rra", true);
		}
		ft_execute(stack_a, stack_b, "pb", true);
	}
	ft_tiny_sort(stack_a);
	while (!ft_stack_empty(stack_b))
		ft_execute(stack_a, stack_b, "pa", true);
	ft_stack_dtor(stack_b);
}

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
	t_node			*tmp;
	t_stack			*stack_b;
	unsigned int	i;
	unsigned int	approximation;

	stack_b = ft_stack_ctor();
	if (!stack_a || !stack_b)
		ft_error();
	approximation = 0.0375 * stack_a->m_size + 11.25;
	i = 1;
	while (stack_a->m_head)
	{
		tmp = stack_a->m_head;
		if (tmp->index <= i && i > 2)
		{
			ft_execute(stack_a, stack_b, "pb", true);
			ft_execute(NULL, stack_b, "rb", true);
			i++;
		}
		else if (tmp->index <= i + approximation + 1)
		{
			ft_execute(stack_a, stack_b, "pb", true);
			i++;
		}
		else
			ft_execute(stack_a, NULL, "ra", true);
	}
	ft_butterfly_helper(stack_a, stack_b);
	ft_stack_dtor(stack_b);
}

void	ft_stack_sort(t_stack *stack)
{
	if (!stack)
		ft_error();
	if (stack->m_size == 2)
	{
		if (stack->m_head->data > stack->m_head->next->data)
			ft_execute(stack, NULL, "sa", true);
	}
	else if (stack->m_size == 3)
		ft_tiny_sort(stack);
	else if (stack->m_size == 4 || stack->m_size == 5)
		ft_simple_sort(stack);
	else
		ft_butterfly_sort(stack);
}
