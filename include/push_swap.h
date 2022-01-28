/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:26:27 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/28 20:09:23 by jeong-yena       ###   ########.fr       */
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
	int		cnt;
}	t_ps;


/*utils*/
void			err_exit(char *str);
void			free_double_str(char **str);
void			parse_arg(int argc, char **argv, t_ps *stack);
void			print_cmd(char	*str);

/*stack*/
void			init_stack(t_ps *stack, int argc);
void			stack_init_data(char *str, t_stack *stack);
t_stack_node	*new_node(int	data);

/*cmd*/
int				swap_top(t_stack *stack);
int				push(t_stack *dst, t_stack *src);
int				rotate(t_stack *stack);
int				rotate_reverse(t_stack *stack);
void			commend(t_ps *ps, char	*cmd);

#endif
