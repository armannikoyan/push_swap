/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:17:36 by anikoyan          #+#    #+#             */
/*   Updated: 2024/07/18 17:03:33 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_swap(t_stack *stack)
{
	t_node	*top;

	if (!stack)
		ft_error();
	if (stack->m_size < 2)
		return ;
	top = stack->m_head;
	stack->m_head = stack->m_head->next;
	top->next = stack->m_head->next;
	stack->m_head->next = top;
}

static void	ft_push(t_stack *dst, t_stack *src)
{
	unsigned int	index;

	if (!dst || !src)
		ft_error();
	ft_stack_push(dst, src->m_head->data);
	index = src->m_head->index;
	dst->m_head->index = index;
	ft_stack_pop(src);
}

static void	ft_rotate(t_stack *stack, bool reverse)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!stack)
		ft_error();
	if (stack->m_size < 2)
		return ;
	tmp = stack->m_head;
	if (!reverse)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stack->m_head;
		stack->m_head = stack->m_head->next;
		tmp->next->next = NULL;
	}
	else
	{
		while (tmp->next && tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = stack->m_head;
		stack->m_head = tmp2;
	}
}

static void	ft_execute_helper(t_stack *stack_a, t_stack *stack_b, char *name)
{
	if (!ft_strcmp("rr", name))
	{
		ft_rotate(stack_a, false);
		ft_rotate(stack_b, false);
	}
	else if (!ft_strcmp("rra", name))
		ft_rotate(stack_a, true);
	else if (!ft_strcmp("rrb", name))
		ft_rotate(stack_b, true);
	else if (!ft_strcmp("rrr", name))
	{
		ft_rotate(stack_a, true);
		ft_rotate(stack_b, true);
	}
}

void	ft_execute(t_stack *stack_a, t_stack *stack_b, char *name, bool print)
{
	if (print)
		ft_printf("%s\n", name);
	if (!ft_strcmp("sa", name))
		ft_swap(stack_a);
	else if (!ft_strcmp("sb", name))
		ft_swap(stack_b);
	else if (!ft_strcmp("ss", name))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (!ft_strcmp("pa", name))
		ft_push(stack_a, stack_b);
	else if (!ft_strcmp("pb", name))
		ft_push(stack_b, stack_a);
	else if (!ft_strcmp("ra", name))
		ft_rotate(stack_a, false);
	else if (!ft_strcmp("rb", name))
		ft_rotate(stack_b, false);
	else
		ft_execute_helper(stack_a, stack_b, name);
}
