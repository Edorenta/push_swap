/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sorting_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:27:14 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/24 11:27:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void			ez_bubble_sort(t_env *env)
{
	t_elem	*tmp;
	int		i;
	int		step;

	while (1)
	{
		step = 0;
		i = 0;
		tmp = env->a_first;
		while (tmp->next && tmp->val < tmp->next->val && ++step)
			tmp = tmp->next;
		if (tmp->next)
		{
			while (i++ < step)
				op_ra(env);
			op_sa(env);
			while (step--)
				op_rra(env);
		}
		else
			break ;
	}
}

void			fifo_bubble_sort(t_env *e)
{
	while (!is_sorted(e))
	{
		while (e->a_first->next && e->a_first->val < e->a_first->next->val)
			op_pb(e);
		op_sa(e);
		if (e->b_first && e->b_first->val > e->a_first->val)
		{
			op_ra(e);
			while (e->b_first && e->b_first->val > e->a_last->val)
				op_pa(e);
			op_rra(e);
		}
	}
	while (e->b_first)
		op_pa(e);
}

static void		lifo_bubble_sort2(t_env *env)
{
	if (env->a_first->val > env->a_first->next->val)
		op_sa(env);
	if (env->b_first && env->b_first->val > env->a_first->val)
	{
		op_ra(env);
		while (env->b_first && env->b_first->val > env->a_last->val)
			op_pa(env);
		op_rra(env);
	}
}

void			lifo_bubble_sort(t_env *env)
{
	while (!is_sorted(env))
	{
		while (env->a_first->val < env->a_last->val)
		{
			lifo_bubble_sort2(env);
			op_pb(env);
		}
		while (env->a_last->val < env->a_first->val)
		{
			while (env->b_first && env->b_first->val > env->a_last->val)
				op_pa(env);
			op_rra(env);
			while (env->a_first->val < env->a_last->val)
			{
				lifo_bubble_sort2(env);
				op_pb(env);
			}
		}
	}
	while (env->b_first)
		op_pa(env);
}
