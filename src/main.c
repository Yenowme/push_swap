/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:14 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/27 18:31:41 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//debug
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
			printf("a: %d  ", a->data);
			a = a->next;
		}
		if (b)
		{
			printf("b: %d", b->data);
			b = b->next;
		}
	}
}


int	main(int argc, char **argv)
{
	t_ps	stack;

	init_stack(&stack, argc);
	parse_arg(argc, argv, &stack);
	print_stack(stack);
}
