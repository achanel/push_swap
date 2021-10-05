/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:10:22 by achanel           #+#    #+#             */
/*   Updated: 2021/10/04 10:48:14 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solver_2(t_base *base)
{
	if (base->a->num > base->a->next->num)
		swap_a(base);
}

static void	solver_3(t_base *base)
{
	t_stack	*tmp;
	t_stack	*stack;
	int	i;

	i = 1;
	do_big(base, 'a');
	tmp = base->a->prev;
	while (tmp->num != base->biggest)
	{
		i++;
		tmp = tmp->prev;
	}
	while (i > 1)
	{
		reverse_rotate_a(base);
		i--;
	}
	stack = base->a;
	tmp = base->a->next;
	if (stack->num > tmp->num)
		swap_a(base);
}

static void	solver_4(t_base *base)
{
	t_stack *stack;

	stack = base->a;
	do_big_small(base, 'a');
	while (stack->num != base->smallest)
	{
		rotate_a(base);
		stack = stack->next;
	}
	push_b(base);
	solver_3(base);
	push_a(base);
}

static void	solver_5(t_base *base)
{
	t_stack	*tmp;
	t_stack	*stack_a_end;
	int		flag;

	stack_a_end = base->a->prev;
	flag = 0;
	find_midle(base, 'a');
	while (flag != 1)
	{
		if (base->a == stack_a_end)
			flag = 1;
		if (base->a->num < base->middle)
			push_b(base);
		else
			rotate_a(base);
	}
	solver_3(base);
	tmp = base->b->next;
	if (base->b->num < tmp->num)
		swap_b(base);
	push_a(base);
	push_a(base);
	// printf("%ld\n", base->a->num);
	// printf("%ld\n", base->a->next->num);
	// printf("%ld\n", base->a->next->next->num);
	// printf("%ld\n", base->a->next->next->next->num);
	// printf("%ld\n", base->a->next->next->next->next->num);
}

void	short_solver(t_base *base)
{
	if (stack_len(base, 'a') == 2)
		solver_2(base);
	if (stack_len(base, 'a') == 3)
		solver_3(base);
	if (stack_len(base, 'a') == 4)
		solver_4(base);
	if (stack_len(base, 'a') == 5)
		solver_5(base);
}
