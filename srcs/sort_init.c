/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:30:03 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/24 11:30:06 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_sorted(t_env *env)
{
	t_elem	*tmp;

	tmp = env->a_first;
	while (tmp && tmp->next && tmp->val < tmp->next->val)
		tmp = tmp->next;
	if (tmp && tmp->next)
		return (0);
	return (1);
}

void	algo_picker(t_env *env)
{
	void	(*choices[5])(t_env*);

	choices[0] = ez_bubble_sort;
	choices[1] = fifo_bubble_sort;
	choices[2] = lifo_bubble_sort;
	choices[3] = push_min;
	choices[4] = quick_sort;
	if (env->a_first)
		choices[env->choice](env);
}

void	begin_sort(t_env *env)
{
	if (env->options & 1 || env->options & 16)
	{
		ft_putstr_fd("		START\n", 1);
		put_option(env);
		ft_putchar('\n');
	}
	if (env->a_first)
		init_op1(env);
	if (env->a_first)
		algo_picker(env);
	ft_putchar('\n');
	if (env->options & 1 || env->options & 16)
	{
		ft_putstr_fd("\n		END\n", 1);
		put_option(env);
		OPT_COUNT ? ft_putchar('\n') : 0;
	}
	free_stack(&(env->a_first), &(env->a_last));
	free_stack(&(env->b_first), &(env->b_last));
	if (OPT_COUNT)
	{
		ft_putstr_fd("Total moves: ", 1);
		ft_putnbr(env->tot);
		ft_putchar('\n');
	}
}
