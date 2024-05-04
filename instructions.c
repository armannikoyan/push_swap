/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:17:36 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/04 00:07:41 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack)
		ft_error();
	if (stack->m_size < 2)
		return ;
	tmp = stack->m_head->data;
	stack->m_head->data = stack->m_head->next->data;
	stack->m_head->next->data = tmp;
}

static void	ft_push(t_stack *dst, t_stack *src)
{
	if (!dst || !src)
		ft_error();
	if (!src->m_head)
		return ;
	ft_stack_push(dst, src->m_head->data);
}

static void	ft_rotate(t_stack *stack, bool reverse)
{
	t_stack	*temp_stack;
	int	temp_data;

	temp_stack = ft_stack_ctor();
	if (!temp_stack)
		ft_error();
	if (!reverse)
		temp_data = stack->m_head->data;
	ft_stack_pop(stack);
	while (stack->m_head)
	{
		ft_stack_push(temp_stack, stack->m_head->data);
		ft_stack_pop(stack);
	}
	if (reverse)
		temp_data = temp_stack->m_head->data;
	else
		ft_stack_push(temp_stack, temp_data);
	while (temp_stack->m_head)
	{
		ft_stack_push(stack, temp_stack->m_head->data);
		ft_stack_pop(temp_stack);
	}
	if (reverse)
		ft_stack_push(stack, temp_data);
	free(temp_stack);
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
	else if (!ft_strcmp("sa", name))
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
