/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:50:04 by anikoyan          #+#    #+#             */
/*   Updated: 2024/05/10 15:41:22 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_error()
{
	write(2, "Error\n", 6);
	exit(-1);
}

static void	ft_number_validation(char *nbr)
{
	int	i;
	int	len;

	if (!nbr)
		ft_error();
	i = 0;
	len = ft_strlen(nbr);
	if (nbr[i] == '-')
	{
		if (len >= 11 && ft_strcmp(nbr, "-2147483648") > 0)
			ft_error();
		i++;
	}
	else if (len >= 10 && ft_strcmp(nbr, "2147483647") > 0)
		ft_error();
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			ft_error();
		i++;
	}
}

void	ft_ensure_valid_input(char **argv)
{
	int	i;
	int	j;

	if (!argv)
		ft_error();
	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				ft_error();
			j++;
		}
		ft_number_validation(argv[i]);
		i++;
	}
}

void	ft_define_stack(char **argv, t_stack *stack)
{
	int	i;

	if (!argv || !stack)
		ft_error();
	i = 0;
	while (argv[i])
		i++;
	--i;
	while (i >= 0)
	{
		ft_stack_push(stack, ft_atoi(argv[i]));
		i--;
	}
}

char	**ft_format_argv(int argc, char **argv)
{
	char	**data;
	int	i;

	if (argc < 2)
		return (NULL);
	else if (argc == 2)
		return (ft_split(argv[1], ' '));
	data = malloc(sizeof(char *) * argc);
	i = 0;
	while (argv[i + 1])
	{
		data[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	data[i] = NULL;
	return (data);
}
