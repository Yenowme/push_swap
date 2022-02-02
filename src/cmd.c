/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:34:55 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/01 17:02:05 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_top(t_stack *stack)
{
	int	tmp;

	if (stack->cnt < 2)
		return (1);
	tmp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = tmp;
	return (1);
}

int	push(t_stack *to, t_stack *from)
{
	t_stack_node	*new;
	t_stack_node	*old;

	old = to->head;
	new = from->head;
	if (!new)
		return (0);
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
	from->cnt--;
	return (++(to->cnt));
}

int	rotate(t_stack *stack)
{
	t_stack_node	*tmp;

	if (stack->cnt < 2)
		return (1);
	if (stack->cnt < 3)
		return (swap_top(stack));
	tmp = stack->head;
	tmp->prev = stack->tail;
	stack->tail->next = tmp;
	stack->head = tmp->next;
	stack->head->prev = NULL;
	stack->tail = tmp;
	tmp->next = NULL;
	return (1);
}

int	rotate_reverse(t_stack *stack)
{
	t_stack_node	*tmp;

	if (stack->cnt < 2)
		return (1);
	if (stack->cnt < 3)
		return (swap_top(stack));
	tmp = stack->tail;
	stack->head->prev = tmp;
	tmp->next = stack->head;
	stack->tail = tmp->prev;
	stack->head = tmp;
	tmp->prev = NULL;
	stack->tail->next = NULL;
	return (1);
}

void	cmd(t_ps *ps, char	*cmd)
{
	if (!ft_strcmp(cmd, "sa") && swap_top(&(ps->a)))
		print_cmd("sa");
	else if (!ft_strcmp(cmd, "sb") && swap_top(&(ps->b)))
		print_cmd("sb");
	else if (!ft_strcmp(cmd, "ss") && swap_top(&(ps->a)) && swap_top(&(ps->b)))
		print_cmd("ss");
	else if (!ft_strcmp(cmd, "pa") && push(&(ps->a), &(ps->b)))
		print_cmd("pa");
	else if (!ft_strcmp(cmd, "pb") && push(&(ps->b), &(ps->a)))
		print_cmd("pb");
	else if (!ft_strcmp(cmd, "ra") && rotate(&(ps->a)))
		print_cmd("ra");
	else if (!ft_strcmp(cmd, "rb") && rotate(&(ps->b)))
		print_cmd("rb");
	else if (!ft_strcmp(cmd, "rr") && rotate(&(ps->a)) && rotate(&(ps->b)))
		print_cmd("rr");
	else if (!ft_strcmp(cmd, "rra") && rotate_reverse(&(ps->a)))
		print_cmd("rra");
	else if (!ft_strcmp(cmd, "rrb") && rotate_reverse(&(ps->b)))
		print_cmd("rrb");
	else if (!ft_strcmp(cmd, "rrr") && rotate_reverse(&(ps->a))
		&& rotate_reverse(&(ps->b)))
		print_cmd("rrr");
}
