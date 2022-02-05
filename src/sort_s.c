/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:09:54 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/05 20:57:31 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_des(t_ps *stack, int cnt)
{
	int	i;

	if (cnt == 2)
		return (cmd(stack, "sa"));
	if (cnt == 3)
	{
		cmd(stack, "sa");
		cmd(stack, "rra");
		return ;
	}
	i = 0;
	while (i++ < cnt)
	{
		cmd(stack, "pb");
		cmd(stack, "rb");
	}
	i = 0;
	while (i++ < cnt)
		cmd(stack, "pa");
}

void	sort_3(t_ps *stack)
{
	t_stack	tmp;

	tmp = stack->a;
	if (tmp.head->data > tmp.head->next->data 
		&& tmp.head->next->data < tmp.tail->data)
		return (cmd(stack, "ra"));
	if (tmp.head->data < tmp.head->next->data)
		cmd(stack, "rra");
	if (tmp.head->next->data < tmp.tail->data)
		cmd(stack, "sa");
}
