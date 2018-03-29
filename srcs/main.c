/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:25:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/05 10:25:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	algo_option(int ac, char **av, t_env *env)
{
	if (ac <= env->index)
		return ;
	if (av[env->index][0] == '-' && av[env->index][1] == 'a')
	{
		if (ft_strequ("-a0", av[env->index]) && ++(env->index))
			env->choice = 0;
		else if (ft_strequ("-a1", av[env->index]) && ++(env->index))
			env->choice = 1;
		else if (ft_strequ("-a2", av[env->index]) && ++(env->index))
			env->choice = 2;
		else if (ft_strequ("-a3", av[env->index]) && ++(env->index))
			env->choice = 3;
		else if (ft_strequ("-a4", av[env->index]) && ++(env->index))
			env->choice = 4;
	}
}

static void	get_options(int ac, char **av, t_env *env)
{
	while (ac > env->index)
	{
		if (ft_strequ("-p", av[env->index]) && (env->index)++)
			env->options += !OPT_PRINT ? 1 : 0;
		else if (ft_strequ("-t", av[env->index]) && ++(env->index))
			env->options += !OPT_COUNT ? 2 : 0;
		else if (ft_strequ("-d", av[env->index]) && ++(env->index))
			env->options += !OPT_STEP ? 8 : 0;
		else if (ft_strequ("-rp", av[env->index]) && ++(env->index))
			env->options += !OPT_RPRINT ? 16 : 0;
		else
			break ;
	}
	if (env->options & 1 && env->options & 16)
		env->options -= 16;
}

int			main(int ac, char **av)
{
	t_env	env;

	env.a_first = NULL;
	env.b_first = NULL;
	env.a_last = NULL;
	env.b_last = NULL;
	env.index = 1;
	env.a_size = 0;
	env.b_size = 0;
	env.tot = 0;
	env.options = 0;
	env.choice = 4;
	get_options(ac, av, &env);
	algo_option(ac, av, &env);
	if (get_stack(ac, av, &env) >= 0)
		begin_sort(&env);
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
