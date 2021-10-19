/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:41:39 by achanel           #+#    #+#             */
/*   Updated: 2021/10/16 16:43:48 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_steps
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				len;
	int				index;
}				t_steps;

typedef struct s_stack
{
	long			number;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_base
{
	t_stack	*a;
	t_stack	*b;
	int		biggest;
	int		smallest;
	int		*array;
	int		len;
	int		ac;
	char	**av;
	t_steps	*steps;
}				t_base;

//do_check.c
void	check_number(char *arg);
void	check_int(char *arg);
t_stack	*check_stack(t_base *base);
//do_duble.c
void	ss_swap(t_stack **stack, t_stack **dst, char *str);
void	rr_rotate(t_stack **stack, t_stack **dst, char *str);
void	rrr_rev_rotate(t_stack **stack, t_stack **dst, char *str);
//do_single.c
void	push(t_stack **stack, t_stack **dst, char *str);
void	swap(t_stack **stack, char *str);
void	rotate(t_stack **stack, char *str);
void	reverse_rotate(t_stack **stack, char *str);
//number_utils.c
void	do_index(t_stack **stack, int *array);
int		*array_to_stack(t_stack *stack);
int		*sort_array(int *array, int size);
int		find_smallest_index(t_stack *stack);
int		do_small(t_stack *stack);
//push_swap.c
void	new_base(t_base *base, int ac, char **av);
void	new_steps(t_steps *steps);
//short_solver.c
void	short_solver(t_base *base, int size);
void	start_sort(t_base *base);
//solver_utils.c
void	sort_b_helper_helper(t_stack **stack_a, t_stack **stack_b,
			t_steps *steps);
void	sort_b_helper(t_stack **stack_a, t_stack **stack_b, t_steps *steps);
void	final_sort(t_stack **stack, t_steps *steps);
int		find_mid_index(t_stack *stack);
//solver.c
int		position_b(t_stack *stack, int index);
int		position_a(t_stack *stack, int index);
int		optimal_move(int total_sum, t_steps *steps);
int		ft_steps_count(t_stack *stack_a, t_stack *stack_b,
			t_steps *steps, int index);
void	sort_b(t_base *base, t_steps *steps);
//stack_utils.c
t_stack	*add_new(int number);
void	stack_add_back(t_stack **stack, int number);
int		stack_len(t_stack *stack);
//utils.c
void	check_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
void	clear_stack(t_stack **stack);
int		push_swap_error(void);
#endif
