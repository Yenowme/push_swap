/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:09:37 by kunlee            #+#    #+#             */
/*   Updated: 2022/02/04 22:37:15 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_arr(t_stack *stack, int cnt, t_pv *pv)
{
	int				i;
	t_stack_node	*tmp;

	pv->arr = (int *)malloc(sizeof(int) * cnt);
	if (!pv->arr)
		err_exit();
	tmp = stack->head;
	i = 0;
	while (i < cnt && tmp)
	{
		pv->arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

void	set_pv(t_stack *stack, int cnt, t_pv *pv)
{
	int	i;
	int	j;
	int	pv_cnt;

	pv->pv_s_cnt = cnt / 3;
	pv->pv_l_cnt = cnt / 3 * 2;
	set_arr(stack, cnt, pv);
	i = 0;
	while (i < cnt)
	{
		j = 0;
		pv_cnt = 0;
		while (j < cnt)
		{
			if (pv->arr[i] > pv->arr[j])
				pv_cnt++;
			j++;
		}
		if (pv_cnt == pv->pv_l_cnt)
			pv->pv_l = pv->arr[i];
		if (pv_cnt == pv->pv_s_cnt)
			pv->pv_s = pv->arr[i];
		i++;
	}
	free(pv->arr);
	pv->arr = NULL;
}
