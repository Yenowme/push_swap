/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:26:27 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/26 21:56:56 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1
typedef struct s_stack_node
{
	int					data;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	int					cnt;
	t_stack_node		*head;
	t_stack_node		*tail;
}	t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
}	t_ps;

void	err_exit(char *str);
void	free_double_str(char **str);
void	parse_arg(int argc, char **argv);
void	stack_add_back(char *str);
void	init_stack(t_ps *stack);

#endif