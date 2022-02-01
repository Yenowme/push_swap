/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:55:03 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/31 18:19:42 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	err_exit(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
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

void	set_pb(t_stack stack, t_pb *pb)
{
	int	tmp;

	pb->pb_s = stack.head->data;
	pb->pb_l = stack.head->next->data;
	if (pb->pb_s > pb->pb_l)
	{
		tmp = pb->pb_l;
		pb->pb_l = pb->pb_s;
		pb->pb_s = tmp;
	}
}
