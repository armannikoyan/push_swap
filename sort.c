/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:05:49 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/11 18:15:55 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	ft_stack_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		ft_error();
	tmp = stack->m_head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static int	ft_stack_max(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	if (!stack)
		ft_error();
	tmp = stack->m_head;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

static int	ft_stack_min(t_stack *stack)
{
	t_node	*tmp;
	int		min;

	if (!stack)
		ft_error();
	tmp = stack->m_head;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_minimal_sort(t_stack *stack)
{
	if (!stack)
		ft_error();
	if (stack->m_size != 2)
		return ;
	if (stack->m_head->data > stack->m_head->next->data)
		ft_execute(stack, NULL, "sa", true);
}

void	ft_tiny_sort(t_stack *stack)
{
	int		max;

	if (!stack)
		ft_error();
	if (stack->m_size != 3)
		return ;
	max = ft_stack_max(stack);
	if (stack->m_head->data == max)
		ft_execute(stack, NULL, "ra", true);
	else if (stack->m_head->next->data == max)
		ft_execute(stack, NULL, "rra", true);
	if (stack->m_head->data > stack->m_head->next->data)
		ft_execute(stack, NULL, "sa", true);
}

void	ft_simple_sort(t_stack *stack_a)
{
	t_stack	*stack_b;
	t_node	*tmp;
	unsigned int	iter_to_min;
	int	min;

	if (!stack_a)
		ft_error();
	if (stack_a->m_size < 4 || stack_a->m_size > 5)
		return ;
	stack_b = ft_stack_ctor();
	while (stack_a->m_size > 3)
	{
		min = ft_stack_min(stack_a);
		tmp = stack_a->m_head;
		iter_to_min = 0;
		while (tmp && stack_a->m_head->data != min)
		{
			tmp = tmp->next;
			iter_to_min++;
		}
		if (iter_to_min > stack_a->m_size / 2)
			while (stack_a->m_head->data != min)
				ft_execute(stack_a, stack_b, "ra", true);
		else
			while (stack_a->m_head->data != min)
				ft_execute(stack_a, stack_b, "rra", true);
		ft_execute(stack_a, stack_b, "pb", true);
	}
	ft_tiny_sort(stack_a);
	while (!ft_stack_empty(stack_b))
		ft_execute(stack_a, stack_b, "pa", true);
	ft_stack_dtor(stack_b);
}
