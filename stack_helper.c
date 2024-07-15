/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:59:01 by anikoyan          #+#    #+#             */
/*   Updated: 2024/07/15 10:00:44 by anikoyan         ###   ########.fr       */
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

int	ft_stack_min(t_stack *stack)
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

int	ft_stack_max(t_stack *stack)
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
