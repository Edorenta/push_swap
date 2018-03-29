/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:47:44 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/27 13:47:46 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_stack(char *str, t_elem **start)
{
	t_elem	*tmp;

	tmp = *start;
	ft_putstr_fd(str, 1);
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->val);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static void	print_revstack(char *str, t_elem **end)
{
	t_elem	*tmp;

	tmp = *end;
	ft_putstr_fd(str, 1);
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->val);
		tmp = tmp->prev;
	}
	ft_putchar('\n');
}

void		print_pause(t_env *env)
{
	char	c[1];

	ft_putchar('\n');
	read(0, &c, 1);
	if (env->options & 16)
		print_revstack("Pile A:", &(env->a_last));
	else
		print_stack("Pile A:", &(env->a_first));
	if (env->options & 16)
		print_revstack("Pile B:", &(env->b_last));
	else
		print_stack("Pile B:", &(env->b_first));
	ft_putchar('\n');
}

void		put_option(t_env *env)
{
	if (env->options & 16)
		print_revstack("Pile A:", &(env->a_last));
	else
		print_stack("Pile A:", &(env->a_first));
	if (env->options & 16)
		print_revstack("Pile B:", &(env->b_last));
	else
		print_stack("Pile B:", &(env->b_first));
}
