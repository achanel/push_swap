/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:47:47 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 16:11:19 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_steps(t_base *base)
{
	base->small_rotate = 0;
	base->big_rotate = 0;
	base->small_re_rotate = 0;
	base->big_re_rotate = 0;
	base->biggest = 0;
	base->smallest = 0;
	base->flag_big = 0;
	base->flag_small = 0;
}

static void	rotate_and_push(t_base *base)
{
	if (base->small_rotate >= 0)
		while (base->small_rotate--)
			rotate_b(base);
	else if (base->small_re_rotate >= 0)
		while (base->small_re_rotate--)
			reverse_rotate_b(base);
	if (base->big_rotate >= 0)
		while (base->big_rotate--)
			rotate_b(base);
	if (base->big_rotate >= 0)
		while (base->big_rotate--)
			reverse_rotate_b(base);
	push_a(base);
	if (base->flag_small == 1)
		rotate_a(base);
	if (base->flag_big == 1 || !base->b)
		base->after_rotate++;
	reset_steps(base);
}

static void	push_big_small(t_base *base)
{
	t_stack *stack;
	t_stack *last;

	stack = base->b;
	last = base->b->prev;
	while (1)
	{
		while (stack->num != base->smallest)
			stack = stack->next;
		if (stack->num == base->smallest || stack->num == base->biggest)
		{
			rotate_and_push(base);
			break ;
		}
		else
			stack = stack->next;
		if (stack == last)
			break ;
		stack = base->b;
	}
}

static void	push_half(t_base *base)
{
	t_stack	*stack;
	t_stack	*last;
	int		i;

	i = 0;
	stack = base->a;
	last = base->a->prev;
	do_small(base, 'a');
	while (1)
	{
		if (stack == last)
			i = 1;
		if (base->base_flag == 1 && stack->num <= base->middle)
			push_b(base);
		else if (base->base_flag == 2 && stack->num > base->middle)
			push_b(base);
		else if (stack->num == base->smallest)
			break ;
		else
			rotate_a(base);
		if (i == 1)
			break ;
		stack = base->a;
	}
	reset_steps(base);
}

void	start_sort(t_base *base)
{
	base->base_flag = 1;
	find_midle(base, 'a');
	while (base->a)
	{
		push_half(base);
		while (base->b)
		{
			do_big_small(base, 'b');
			steps_counter(base, 'b');
			if (base->b && (base->small_rotate >= 0 || base->small_re_rotate >= 0 ||
				base->big_rotate >= 0 || base->big_re_rotate >= 0))
				push_big_small(base);
		}
		while (--base->after_rotate > -1)
			rotate_a(base);
		base->base_flag++;
		if (base->base_flag == 3)
			break ;
	}
}
