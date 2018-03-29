/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:35:54 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/05 10:35:57 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_sa(t_env *e)
{
	t_elem	*tmp1;

	if (e->a_first && e->a_first->next)
	{
		tmp1 = e->a_first->next;
		e->a_first->next->next ? e->a_first->next->next->prev = e->a_first : 0;
		!(e->a_first->next->next) ? e->a_last = e->a_first : 0;
		e->a_first->next = e->a_first->next->next;
		e->a_first->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = e->a_first;
		e->a_first = tmp1;
		++(e->tot);
		((e->tot) != 1) ? ft_putstr_fd(" sa", 1) : ft_putstr_fd("sa", 1);
		if (e->options & 8)
			print_pause(e);
	}
}

void	op_sb(t_env *e)
{
	t_elem	*tmp1;

	if (e->b_first && e->b_first->next)
	{
		tmp1 = e->b_first->next;
		e->b_first->next->next ? e->b_first->next->next->prev = e->b_first : 0;
		!(e->b_first->next->next) ? e->b_last = e->b_first : 0;
		e->b_first->next = e->b_first->next->next;
		e->b_first->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = e->b_first;
		e->b_first = tmp1;
		++(e->tot);
		((e->tot) != 1) ? ft_putstr_fd(" sb", 1) : ft_putstr_fd("sb", 1);
		if (e->options & 8)
			print_pause(e);
	}
}

void	op_ss(t_env *e)
{
	t_elem	*tmp1;

	if (e->a_first && e->a_first->next)
	{
		tmp1 = e->a_first->next;
		e->a_first->next->next ? e->a_first->next->next->prev = e->a_first : 0;
		!(e->a_first->next->next) ? e->a_last = e->a_first : 0;
		e->a_first->next = e->a_first->next->next;
		e->a_first->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = e->a_first;
		e->a_first = tmp1;
	}
	if (e->b_first && e->b_first->next && (tmp1 = e->b_first->next))
	{
		e->b_first->next->next ? e->b_first->next->next->prev = e->b_first : 0;
		!(e->b_first->next->next) ? e->b_last = e->b_first : 0;
		e->b_first->next = e->b_first->next->next;
		e->b_first->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = e->b_first;
		e->b_first = tmp1;
	}
	((e->tot) != 1) ? ft_putstr_fd(" ss", 1) : ft_putstr_fd("ss", 1);
	(e->options & 8) ? print_pause(e) : 0;
}

void	op_pa(t_env *env)
{
	t_elem	*tmp1;

	if (env->b_first)
	{
		tmp1 = env->b_first;
		env->b_first = tmp1->next;
		(env->b_first) ? env->b_first->prev = NULL : 0;
		!(env->b_first) ? env->b_last = NULL : 0;
		env->a_first ? env->a_first->prev = tmp1 : 0;
		tmp1->next = env->a_first;
		env->a_first = tmp1;
		!((env->a_first)->next) ? env->a_last = env->a_first : 0;
		++(env->tot);
		((env->tot) != 1) ? ft_putstr_fd(" pa", 1) : ft_putstr_fd("pa", 1);
		if (env->options & 8)
			print_pause(env);
		env->a_size++;
		env->b_size--;
	}
}

void	op_pb(t_env *env)
{
	t_elem	*tmp1;

	if (env->a_first)
	{
		tmp1 = env->a_first;
		env->a_first = tmp1->next;
		(env->a_first) ? env->a_first->prev = NULL : 0;
		!(env->a_first) ? env->a_last = NULL : 0;
		env->b_first ? env->b_first->prev = tmp1 : 0;
		tmp1->next = env->b_first;
		env->b_first = tmp1;
		!(env->b_first->next) ? env->b_last = env->b_first : 0;
		++(env->tot);
		((env->tot) != 1) ? ft_putstr_fd(" pb", 1) : ft_putstr_fd("pb", 1);
		if (env->options & 8)
			print_pause(env);
		env->b_size++;
		env->a_size--;
	}
}
