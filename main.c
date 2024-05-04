/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:08:57 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/04 22:59:24 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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

	stack = ft_stack_ctor();
	data = ft_format_argv(argc, argv);
	if (argc == 1 || !data[1])
	{
		ft_free_data(data);
		exit(0);
	}
	ft_ensure_valid_input(data);
	ft_define_stack(data, stack);
	ft_free_data(data);
	while (!ft_stack_empty(stack))
	{
		ft_printf("%d\n", stack->m_head->data);
		ft_stack_pop(stack);
	}
}
