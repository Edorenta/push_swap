/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:22:20 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/05 10:22:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define A_FIRST	env->a_first->val
# define A_NEXT		env->a_first->next->val
# define A_LAST		env->a_last->val

typedef struct		s_elem
{
	int				val;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_env
{
	int				index;
	int				options;
	int				a_size;
	int				b_size;
	int				tot;
	int				pivot;
	int				choice;
	t_elem			*a_first;
	t_elem			*b_first;
	t_elem			*a_last;
	t_elem			*b_last;
}					t_env;

void				op_sa(t_env *env);
void				op_sb(t_env *env);
void				op_ss(t_env *env);
void				op_pa(t_env *env);
void				op_pb(t_env *env);
void				op_ra(t_env *env);
void				op_rb(t_env *env);
void				op_rr(t_env *env);
void				op_rra(t_env *env);
void				op_rrb(t_env *env);
void				op_revrr(t_env *env);

int					get_stack(int argc, char **argv, t_env *env);
void				begin_sort(t_env *env);
void				init_op1(t_env *env);

int					is_sorted(t_env *env);
void				free_stack(t_elem **start, t_elem **end);
void				put_option(t_env *env);
void				print_pause(t_env *env);

void				ez_bubble_sort(t_env *env);
void				fifo_bubble_sort(t_env *env);
void				lifo_bubble_sort(t_env *env);
void				push_min(t_env *env);
void				quick_sort(t_env *env);

int					ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
int					ft_strequ(char const *s1, char const *s2);

#endif
