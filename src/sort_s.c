/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:09:54 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/05 22:52:34 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	get_max_2(t_stack *stack, int cnt, int *min, int *next_min)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	tmp = stack->head;
	*min = 2147483647;
	while (i++ < cnt)
	{
		if (*min > tmp->data)
		{
			*next_min = *min;
			*min = tmp->data;
		}
		else if (*next_min > tmp->data)
			*next_min = tmp->data;
		tmp = tmp->next;
	}
}

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
	t_stack	*tmp;

	tmp = &(stack->a);
	if (tmp->head->data > tmp->head->next->data
		&& tmp->head->next->data < tmp->tail->data
		&& tmp->head->data > tmp->tail->data)
		return (cmd(stack, "ra"));
	if (tmp->head->data < tmp->head->next->data)
		cmd(stack, "rra");
	if (!is_ascending(stack->a, 3) && tmp->head->next->data < tmp->tail->data)
		cmd(stack, "sa");
}

void	sort_5(t_ps *stack)
{
	int				min[2];
	int				i;
	t_stack			*tmp;

	tmp = &(stack->a);
	get_max_2(tmp, 5, &min[0], &min[1]);
	i = 0;
	while (i++ < 5)
	{
		if (tmp->head->data == min[0] || tmp->head->data == min[1])
			cmd(stack, "pb");
		else
			cmd(stack, "ra");
	}
	if (stack->b.head->data == min[0])
		cmd(stack, "rb");
	if (is_descending(stack->a, 3))
		sort_des(stack, 3);
	else if (!is_ascending(stack->a, 3))
		sort_3(stack);
	cmd(stack, "pa");
	cmd(stack, "pa");
}
