/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:10:22 by achanel           #+#    #+#             */
/*   Updated: 2021/10/15 12:31:50 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solver_3(t_base *base)
{
	t_stack	*stack;
	int		first;
	int		second;
	int		third;

	stack = base->a;
	first = stack->number;
	second = stack->next->number;
	third = stack->next->next->number;
	if (first > second && first > third && second > third)
	{
		swap(&(base->a), "sa\n");
		reverse_rotate(&(base->a), "rra\n");
	}
	else if (first < second && third > first && second > third)
	{
		swap(&(base->a), "sa\n");
		rotate(&(base->a), "ra\n");
	}
	else if (third < first && third < second && first < second)
		reverse_rotate(&(base->a), "rra\n");
	else if (first > second && first < third && third > second)
		swap(&(base->a), "sa\n");
	else if (first > third && third > second && first > second)
		rotate(&(base->a), "ra\n");
}

static void	solver_4(t_base *base)
{
	int		small;

	small = do_small(base->a);
	while (base->a->number != small)
		rotate(&(base->a), "ra\n");
	push(&(base->a), &(base->b), "pb\n");
	solver_3(base);
	push(&(base->b), &(base->a), "pa\n");
}

static void	solver_5(t_base *base)
{
	t_stack	*tmp;
	t_stack	*last;
	int		flag;

	flag = 0;
	last = base->a;
	while (last->next)
		last = last->next;
	while (flag != 1)
	{
		if (base->a == last)
			flag = 1;
		if (base->a->index < find_mid_index(base->a))
			push(&(base->a), &(base->b), "pb\n");
		else
			rotate(&(base->a), "ra\n");
	}
	solver_3(base);
	tmp = base->b->next;
	if (tmp != NULL)
		if (base->b->number < tmp->number)
			swap(&(base->b), "sb\n");
	push(&(base->b), &(base->a), "pa\n");
	push(&(base->b), &(base->a), "pa\n");
}

void	short_solver(t_base *base, int size)
{
	if (size == 2)
		if (base->a->number > base->a->next->number)
			swap(&(base->a), "sa\n");
	if (size == 3)
		solver_3(base);
	if (size == 4)
		solver_4(base);
	if (size == 5)
		solver_5(base);
}

void	start_sort(t_base *base)
{
	t_steps	steps;

	while (stack_len(base->a) > 5)
	{
		if (base->a->index > base->len - 5)
			rotate(&(base->a), "ra\n");
		else
			push(&(base->a), &(base->b), "pb\n");
	}
	if (stack_len(base->a) <= 5)
		short_solver(base, stack_len(base->a));
	while (stack_len(base->b))
		sort_b(base, &steps);
	final_sort(&(base->a), &steps);
}
