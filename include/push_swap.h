/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:26:27 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/31 18:32:57 by jeong-yena       ###   ########.fr       */
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

typedef struct s_pb
{
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;
	int	pa_cnt;
	int	pb_s;
	int	pb_l;
	int	idx;
}	t_pb;

/*utils*/
void			err_exit(char *str);
void			free_double_str(char **str);
void			parse_arg(int argc, char **argv, t_ps *stack);
void			print_cmd(char	*str);
void			set_pb(t_stack stack, t_pb *pb);

/*stack*/
void			init_stack(t_ps *stack);
void			stack_init_data(char *str, t_stack *stack);
t_stack_node	*new_node(int	data);

/*cmd*/
int				swap_top(t_stack *stack);
int				push(t_stack *dst, t_stack *src);
int				rotate(t_stack *stack);
int				rotate_reverse(t_stack *stack);
void			cmd(t_ps *ps, char	*cmd);

void			a_to_b(t_ps	*stack, int cnt);
void			b_to_a(t_ps	*stack, int cnt);

void			print_stack(t_ps ps);

#endif
