/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:08:57 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/11 18:16:14 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
	if (argc == 1 || !data[1])
		exit(0);
	stack = ft_stack_ctor();
	ft_ensure_valid_input(data);
	ft_define_stack(data, stack);
	ft_free_data(data);
	if (ft_stack_sorted(stack))
		exit(0);
	ft_minimal_sort(stack);
	ft_tiny_sort(stack);
	ft_simple_sort(stack);
	// while (!ft_stack_empty(stack))
	// {
	// 	ft_printf("%d\n", stack->m_head->data);
	// 	ft_stack_pop(stack);
	// }
	ft_stack_dtor(stack);
}
