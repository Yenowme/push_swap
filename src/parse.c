/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:53:57 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/27 18:26:55 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_split_and_valid(char *str)
{
	int		is_split;
	int		i;

	i = 0;
	is_split = FALSE;
	while (ft_isdigit(str[i]) || str[i] == ' '
		|| str[i] == '-' || str[i] == '+')
	{
		if (str[i] == ' ')
			is_split = TRUE;
		if (str[i] == '-' || str[i] == '+')
			if (!ft_isdigit(str[i + 1]))
				err_exit("is not number\n");
		i++;
	}
	if (str[i] != '\0')
		err_exit("is not number\n");
	return (is_split);
}


void	parse_arg(int argc, char **argv, t_ps *stack)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (i++ < argc - 1)
	{
		if (is_split_and_valid(argv[i]))
		{
			split = ft_split(argv[i], ' ');
			j = 0;
			while (split[j])
				stack_init_data(split[j++], &stack->a);
			free_double_str(split);
		}
		else
			stack_init_data(argv[i], &stack->a);
	}
}
