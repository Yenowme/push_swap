/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:55:03 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/04 22:21:34 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	err_exit(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	print_cmd(char	*str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

