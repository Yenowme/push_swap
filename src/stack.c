/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:24:31 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/26 21:54:44 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_add_back(char *str)
{
	//TODO: add stack a tail
	printf("str: %d\n", ft_atoi(str));
}

void	init_stack(t_ps *stack)
{
	ft_bzero(stack, sizeof(t_ps));
}

