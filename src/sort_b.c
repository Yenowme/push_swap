/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:13:28 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/04 22:22:47 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_some_b(t_ps *stack, int cnt)
{
	//printf("sort_som_b\n");
	if (cnt == 0)
		return ;
	if (cnt == 1)
		return (cmd(stack, "pa"));
	if (stack->b.head->data < stack->b.head->next->data)
		cmd(stack, "sb");
	if (cnt == 3)
	{
		if ( stack->b.head->next->next->data > stack->b.head->next->data)
		{
			cmd(stack, "rb");
			cmd(stack, "sb");
			cmd(stack, "rrb");
			if (stack->b.head->data < stack->b.head->next->data)
				cmd(stack, "sb");
		}
		cmd(stack, "pa");
	}
	cmd(stack, "pa");
	cmd(stack, "pa");
	//print_stack(*stack);
}

void	divde_b(t_ps *stack, int cnt, t_pv *pb)
{
	int				i;
	t_stack_node	*tmp;

	//printf("divide_b\n");

	i = 0;
	while (i < cnt)
	{
		tmp = stack->b.head;
		if (tmp->data < pb->pv_s)
		{
			cmd(stack, "rb");
			pb->rb_cnt++;
		}
		else
		{
			cmd(stack, "pa");
			pb->pa_cnt++;
			if (tmp->data < pb->pv_l)
			{
				cmd(stack, "ra");
				pb->ra_cnt++;
			}
		}
		i++;
	}
	//print_stack(*stack);
}

void	rotate_b(t_ps *stack, t_pv *pb)
{
	int	i;

	i = 0;
	//printf("rotate_b\n");
	while (i < pb->ra_cnt && i < pb->rb_cnt)
	{
		i++;
		cmd(stack, "rrr");
	}
	while (i < pb->rb_cnt)
	{
		cmd(stack, "rrb");
		i++;
	}
	while (i < pb->ra_cnt)
	{
		cmd(stack, "rra");
		i++;
	}
	//print_stack(*stack);
}

void	b_to_a(t_ps	*stack, int cnt)
{
	t_pv	pb;

	ft_bzero(&pb, sizeof(t_pv));
	if (cnt < 4)
		return (sort_some_b(stack, cnt));
	set_pv(&(stack->b), cnt, &pb);
	divde_b(stack, cnt, &pb);
	a_to_b(stack, pb.pa_cnt - pb.ra_cnt);
	rotate_b(stack, &pb);
	a_to_b(stack, pb.ra_cnt);
	b_to_a(stack, pb.rb_cnt);
}
