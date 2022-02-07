/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:14 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/07 18:03:05 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_ps stack)
{
	t_stack_node	*tmp;

	while (stack.a.head)
	{
		tmp = stack.a.head;
		stack.a.head = stack.a.head->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_ps	stack;

	init_stack(&stack);
	parse_arg(argc, argv, &stack);
	if (is_ascending(stack.a, stack.cnt))
	{
		free_stack(stack);
		return (0);
	}
	else if (is_descending(stack.a, stack.cnt) && stack.cnt != 5)
		sort_des(&stack, stack.cnt);
	else if (stack.cnt == 5)
		sort_5(&stack);
	else if (stack.cnt <= 3)
		sort_3(&stack);
	else if (stack.cnt)
		a_to_b(&stack, stack.cnt);
	free_stack(stack);
}
