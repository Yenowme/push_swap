/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:06:50 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/05 20:48:35 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_ascending(t_stack stack, int cnt)
{
	int				i;
	t_stack_node	*tmp;

	tmp = stack.head;
	i = 0;
	while (i < cnt && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}

int	is_descending(t_stack stack, int cnt)
{
	int				i;
	t_stack_node	*tmp;

	tmp = stack.head;
	i = 0;
	while (i < cnt && tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}	
