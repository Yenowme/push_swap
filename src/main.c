/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:14 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/05 21:00:46 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_ps ps)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = ps.a.head;
	b = ps.b.head;
	while (a || b)
	{
		if (a)
		{
			printf("a: %4d ", a->data);
			a = a->next;
		}
		else
		{
			printf("        ");
		}
		if (b)
		{
			printf("b: %4d ", b->data);
			b = b->next;
		}
		else
		{
			printf("        ");
		}
		printf("\n");
	}
	printf("---\n");
	printf("cnt a:%d, b:%d\n\n", ps.a.cnt, ps.b.cnt);
}

void	print_reverse(t_ps ps)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = ps.a.tail;
	b = ps.b.tail;
	while (a || b)
	{
		if (a)
		{
			printf("a: %d", a->data);
			a = a->prev;
		}
		if (b)
		{
			printf("b: %d", b->data);
			b = b->prev;
		}
		printf("\n");
	}
	printf("---\n");
	printf("cnt a:%d, b:%d\n\n", ps.a.cnt, ps.b.cnt);
}

int	main(int argc, char **argv)
{
	t_ps	stack;

	init_stack(&stack);
	parse_arg(argc, argv, &stack);
	if (is_ascending(stack.a, stack.cnt))
		return (0);
	else if (is_descending(stack.a, stack.cnt))
		sort_des(&stack, stack.cnt);
	else if (stack.cnt <= 3)
		sort_3(&stack);
	//else if (stack.cnt <= 5)
		//sort_5(&stack);
	else if (stack.cnt)
		a_to_b(&stack, stack.cnt);
	//print_stack(stack);
}
