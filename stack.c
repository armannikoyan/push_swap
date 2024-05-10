/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:55 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/10 22:45:06 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_stack_ctor(void)
{
	t_stack	*stack;

	stack = NULL;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_error();
	stack->m_head = NULL;
	stack->m_size = 0;
	return (stack);
}

bool	ft_stack_empty(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->m_size == 0);
}

void	ft_stack_push(t_stack *stack, int data)
{
	t_node	*node;

	if (!stack)
		ft_error();
	node = NULL;
	node = malloc(sizeof(t_node));
	if (!node)
		ft_error();
	node->data = data;
	node->next = stack->m_head;
	stack->m_head = node;
	stack->m_size += 1;
}

void	ft_stack_pop(t_stack *stack)
{
	t_node	*top;

	if (!stack)
		ft_error();
	top = stack->m_head;
	if (!top)
		ft_error();
	stack->m_head = stack->m_head->next;
	free(top);
	stack->m_size -= 1;
}

void	ft_stack_dtor(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->m_head)
		ft_stack_pop(stack);
	free(stack);
}
