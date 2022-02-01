/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:48:09 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/31 18:47:43 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_some_a(t_ps *stack, int cnt)
{
	if (stack->a.head->data > stack->a.head->next->data)
		cmd(stack, "sa");
	if (cnt == 3 && stack->a.tail->data < stack->a.tail->prev->data )
	{
		cmd(stack, "ra");
		cmd(stack, "sa");
		cmd(stack, "rra");
		if (stack->a.head->data > stack->a.head->next->data)
			cmd(stack, "sa");
	}
}

void	divde_a(t_ps *stack, int cnt, t_pb *pb)
{
	int	i;
	t_stack_node	*tmp;

	i = 0;
	printf("%d %d\n", pb->pb_l, pb->pb_s);
	while (i < cnt)
	{
		tmp = stack->a.head;
		if (tmp->data >= pb->pb_l)
		{
			cmd(stack, "ra");
			pb->ra_cnt++;
		}
		else
		{
			cmd(stack, "pb");
			pb->pb_cnt++;
			if (tmp->data >= pb->pb_s)
			{
				cmd(stack, "rb");
				pb->rb_cnt++;
			}
		}
		i++;
	}
}

void	rotate_a(t_ps *stack, t_pb *pb)
{
	int	i;

	i = 0;
	while (i < pb->ra_cnt && i < pb->rb_cnt)
	{
		i++;
		cmd(stack, "rrr");
	}
	while (i < pb->ra_cnt)
	{
		cmd(stack, "rra");
		i++;
	}
	while (i < pb->rb_cnt)
	{
		cmd(stack, "rrb");
		i++;
	}
}

void	a_to_b(t_ps	*stack, int cnt)
{
	t_pb			pb;

	ft_bzero(&pb, sizeof(t_pb));
	if (cnt < 4)
		return (sort_some_a(stack, cnt));
	set_pb(stack->a, &pb);
	divde_a(stack, cnt, &pb);
	a_to_b(stack, pb.ra_cnt);
	print_stack(*stack);
	b_to_a(stack, pb.rb_cnt);
	print_stack(*stack);
	b_to_a(stack, pb.pb_cnt - pb.rb_cnt);
	print_stack(*stack);
	rotate_a(stack, &pb);
}
