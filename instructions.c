/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:17:36 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/10 22:42:36 by anikoyan         ###   ########.fr       */
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
	ft_stack_push(dst, src->m_head->data);
	ft_stack_pop(src);
}

static void	ft_rotate(t_stack *stack, bool reverse)
{
	int		tmp;
	t_stack	*tmp_stack;

	if (!stack)
		ft_error();
	if (stack->m_size < 2)
		return ;
	tmp_stack = ft_stack_ctor();
	tmp = stack->m_head->data;
	if (!reverse)
		ft_stack_pop(stack);
	while (!ft_stack_empty(stack))
		ft_execute(stack, tmp_stack, "pb", false);
	if (!reverse)
		ft_stack_push(stack, tmp);
	tmp = tmp_stack->m_head->data;
	if (reverse)
		ft_stack_pop(tmp_stack);
	while (!ft_stack_empty(tmp_stack))
		ft_execute(stack, tmp_stack, "pa", false);
	if (reverse)
		ft_stack_push(stack, tmp);
	ft_stack_dtor(tmp_stack);
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
