/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:14 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/26 21:18:43 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	err_exit(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(1);
}

void	stack_add_back(char *str)
{
	//TODO: add stack a tail
	printf("str: %s\n", str);
}

void	check_arg(char *str)
{
	char	**split;
	int		is_split;
	int		i;

	i = 0;
	is_split = FALSE;
	while (ft_isdigit(str[i]) || str[i] == ' ')
	{
		if (str[i] == ' ')
			is_split = TRUE;
		i++;
	}
	if (str[i] != '\0')
		err_exit("is not number\n");
	else if (is_split)
	{
		split = ft_split(str, ' ');
		while (*split)
			stack_add_back(*split++);
	}
	else
		stack_add_back(str);
}

void	parse_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i++ < argc - 1)
		check_arg(argv[i]);
}

void	init_stack(t_ps *stack)
{
	ft_bzero(stack, sizeof(t_ps));
}

int	main(int argc, char **argv)
{
	t_ps	stack;

	init_stack(&stack);
	parse_arg(argc, argv);
}
