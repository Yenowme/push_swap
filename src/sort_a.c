/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:48:09 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/04 22:22:50 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_some_a(t_ps *stack, int cnt)
{
	//printf("sort_som_a\n");
	if (cnt < 2)
		return ;
	if (stack->a.head->data > stack->a.head->next->data)
		cmd(stack, "sa");
	if (cnt == 3 && stack->a.head->next->next->data 
		< stack->a.head->next->data )
	{
		cmd(stack, "ra");
		cmd(stack, "sa");
		cmd(stack, "rra");
		if (stack->a.head->data > stack->a.head->next->data)
			cmd(stack, "sa");
	}
	//print_stack(*stack);
}

void	divde_a(t_ps *stack, int cnt, t_pv *pb)
{
	int				i;
	t_stack_node	*tmp;

	//printf("divide_a\n");
	i = 0;
	while (i < cnt)
	{
		tmp = stack->a.head;
		if (tmp->data >= pb->pv_l)
		{
			cmd(stack, "ra");
			pb->ra_cnt++;
		}
		else
		{
			cmd(stack, "pb");
			pb->pb_cnt++;
			if (tmp->data >= pb->pv_s)
			{
				cmd(stack, "rb");
				pb->rb_cnt++;
			}
		}
		i++;
	}
	//print_stack(*stack);
}

void	rotate_a(t_ps *stack, t_pv *pb)
{
	int	i;

	//printf("rotate_a\n");
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
	//print_stack(*stack);
}

void	a_to_b(t_ps	*stack, int cnt)
{
	t_pv			pb;

	ft_bzero(&pb, sizeof(t_pv));
	if (cnt < 4)
		return (sort_some_a(stack, cnt));
	set_pv(&(stack->a), cnt, &pb);
	divde_a(stack, cnt, &pb);
	rotate_a(stack, &pb);
	a_to_b(stack, pb.ra_cnt);
	b_to_a(stack, pb.rb_cnt);
	b_to_a(stack, pb.pb_cnt - pb.rb_cnt);
}
