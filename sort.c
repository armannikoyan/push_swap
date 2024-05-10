/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:05:49 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/10 19:41:52 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_tiny_sort(t_stack *stack_a)
{
	int		max;
	t_node	*tmp;

	if (!stack_a || stack_a->m_size != 3)
		return ;
	max = INT_MIN;
	tmp = stack_a->m_head;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	if (stack_a->m_head->data == max)
		ft_execute(stack_a, NULL, "ra", true);
	else if (stack_a->m_head->next->data == max)
		ft_execute(stack_a, NULL, "rra", true);
	if (stack_a->m_head->data > stack_a->m_head->next->data)
		ft_execute(stack_a, NULL, "sa", true);
}
