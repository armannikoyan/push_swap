/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:08:57 by anikoyan          #+#    #+#             */
/*   Updated: 2024/07/18 17:13:38 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_dublicate_check(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack->m_head;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				ft_error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static void	ft_free_data(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
	data = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**data;

	data = ft_format_argv(argc, argv);
	if (argc == 1)
		exit(0);
	stack = ft_stack_ctor();
	ft_ensure_valid_input(data);
	ft_define_stack(data, stack);
	ft_dublicate_check(stack);
	ft_free_data(data);
	if (ft_stack_sorted(stack))
		exit(0);
	ft_stack_index(stack);
	ft_stack_sort(stack);
	ft_stack_dtor(stack);
}
