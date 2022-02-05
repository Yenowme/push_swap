/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:26:27 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/05 20:46:38 by jeong-yena       ###   ########.fr       */
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

typedef struct s_pv
{
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;
	int	pa_cnt;
	int	pv_s;
	int	pv_l;
	int	pv_s_cnt;
	int	pv_l_cnt;
	int	*arr;
}	t_pv;

/*utils*/
void			err_exit(void);
void			free_double_str(char **str);
void			parse_arg(int argc, char **argv, t_ps *stack);
void			print_cmd(char	*str);

/*pivot*/
void	set_pv(t_stack *stack, int cnt, t_pv *pv);

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

/*sort*/

int				is_ascending(t_stack stack, int cnt);
int				is_descending(t_stack stack, int cnt);
void			sort_3(t_ps *stack);
void			sort_des(t_ps *stack, int cnt);

void			print_stack(t_ps ps);

#endif
