/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:24:31 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/27 18:30:40 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_add_back(t_stack *stack, t_stack_node *new)
{	
	if (stack->cnt == 0)
	{
		stack->head = new;
		stack->tail = stack->head;
	}
	else
	{
		new->prev = stack->tail;
		stack->tail->next = new;
		stack->tail = new;
	}
	stack->cnt++;
}

void	stack_init_data(char *str, t_stack *stack)
{
	int				data;
	t_stack_node	*tmp;

	data = ft_atoi(str);
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data == data)
			err_exit("duplicate data\n");
		tmp = tmp->next;
	}
	stack_add_back(stack, new_node(data));
}

void	init_stack(t_ps *stack, int argc)
{
	ft_bzero(stack, sizeof(t_ps));
	stack->cnt = argc;
}

t_stack_node	*new_node(int	data)
{
	t_stack_node	*rt;

	rt = malloc(sizeof(t_stack_node));
	if (!rt)
		return (0);
	rt->data = data;
	rt->next = 0;
	rt->prev = 0;
	return (rt);
}
