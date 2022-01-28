/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:34:55 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/28 19:55:23 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_top(t_stack *stack)
{
	int	tmp;

	if (stack->cnt < 2)
		return ;
	tmp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = tmp;
}

void	push(t_stack *to, t_stack *from)
{
	t_stack_node	*new;
	t_stack_node	*old;

	old = to->head;
	new = from->head;
	if (!new)
		return ;
	if (!old)
		to->tail = new;
	else
		old->prev = new;
	to->head = new;
	if (from->cnt > 1)
	{
		from->head = new->next;
		new->next->prev = NULL;
	}
	else
	{
		from->head = NULL;
		from->tail = NULL;
	}
	new->next = old;
	to->cnt++;
	from->cnt--;
}

void	rotate(t_stack *stack)
{
	t_stack_node	*tmp;

	if (stack->cnt < 2)
		return ;
	if (stack->cnt < 3)
		return (swap_top(stack));
	tmp = stack->head;
	tmp->prev = stack->tail;
	stack->tail->next = tmp;
	stack->head = tmp->next;
	stack->head->prev = NULL;
	stack->tail = tmp;
	tmp->next = NULL;
}

void	rotate_reverse(t_stack *stack)
{
	t_stack_node	*tmp;

	if (stack->cnt < 2)
		return ;
	if (stack->cnt < 3)
		return (swap_top(stack));
	tmp = stack->tail;
	stack->head->prev = tmp;
	tmp->next = stack->head;
	stack->tail = tmp->prev;
	stack->head = tmp;
	tmp->prev = NULL;
	stack->tail->next = NULL;
}

void	commend(char	*cmd)
{
	if (ft_strcmp(cmd, "sa"))
		printf("hi");
}
