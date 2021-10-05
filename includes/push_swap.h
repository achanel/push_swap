/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:41:39 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 16:11:40 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //delete
# include "../libft/libft.h"

typedef struct s_stack
{
	long			num;
	struct s_stack	*prev;
	struct s_stack	*next;
	// int				flag;
	// int				order;
}				t_stack;

typedef struct s_base
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				smallest;
	int				biggest;
	int				middle;
	int				stack_len;
	int				base_flag;
	// int				next_elem;
	int				small_rotate;
	int				big_rotate;
	int				small_re_rotate;
	int				big_re_rotate;
	int				flag_small;
	int				flag_big;
	int				after_rotate;
}				t_base;

//do_check.c
int		check_stack(t_base *base, char **av);
//stack_utils.c
void	stack_add_back(t_base *base, char stack_name, int number);
void	stack_add_front(t_base *base, char stack_name, int number);
void	stack_del_top(t_base *base, char stack_name);
int		stack_len(t_base *base, char stack_name);
//do_big_small.c
void	do_big(t_base *base, char stack_name);
void	do_small(t_base *base, char	stack_name);
void	do_big_small(t_base *base, char	stack_name);
//number_utils.c
void	sort_array(long *array, t_base *base);
void	find_midle(t_base *base, char stack_name);
//utils.c
void	free_base(t_base *base);
int		is_sorted(t_base *base);
int		push_swap_error(t_base *base);
//do_swap.c
void	swap_a(t_base *base);
void	swap_b(t_base *base);
void	swap_ss(t_base *base);
void	reverse_rotate_rrr(t_base *base);
//do_push.c
void	push_a(t_base *base);
void	push_b(t_base *base);
//do_rotate.c
void	rotate_a(t_base *base);
void	rotate_b(t_base *base);
void	rotate_rr(t_base *base);
void	reverse_rotate_a(t_base *base);
void	reverse_rotate_b(t_base *base);
//short_solver.c
void	short_solver(t_base *base);
//solver.c
// void	final_sort(t_base *base);
// void	sort_a(t_base *base);
// void	sort_b(t_base *base);
void	start_sort(t_base *base);
//steps_counter.c
void	steps_counter(t_base *base, char stack_name);
#endif
