/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:08:57 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/10 14:27:19 by anikoyan         ###   ########.fr       */
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

	data = ft_format_argv(argc, argv);
	if (argc == 1 || !data[1])
		exit(0);
	stack = ft_stack_ctor();
	ft_ensure_valid_input(data);
	ft_define_stack(data, stack);
	ft_free_data(data);
	ft_tiny_sort(stack);
	ft_stack_dtor(stack);
}
