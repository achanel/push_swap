/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:34:26 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 16:15:37 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	steps_to_end(t_base *base, char stack_name, int flag)
{
	t_stack	*stack;
	long	number;

	if (stack_name == 'a')
		stack = base->a;
	else
		stack = base->b;
	if (stack)
	{
		if (flag == 1)
			number = base->smallest;
		else
			number = base->biggest;
		while (stack->num != number)
		{
			if (flag == 1)
				base->small_re_rotate++;
			else
				base->big_re_rotate++;
			stack = stack->next;
		}
	}
}

static void	steps_to_start(t_base *base, char stack_name, int flag)
{
	t_stack	*stack;
	long	number;

	if (stack_name == 'a')
		stack = base->a;
	else
		stack = base->b;
	if (stack)
	{
		if (flag == 1)
			number = base->smallest;
		else
			number = base->biggest;
		while (stack->num != number)
		{
			if (flag == 1)
				base->small_rotate++;
			else
				base->big_rotate++;
			stack = stack->next;
		}
	}
}

static void	steps_to_big(t_base *base, char stack_name)
{
	t_stack *stack;
	int		flag;

	if (stack_name == 'a')
		stack = base->a;
	else
		stack = base->b;
	flag = 2;
	if (stack)
	{
		steps_to_start(base, stack_name, flag);
		steps_to_end(base, stack_name, flag);
		if (base->small_rotate <= base->small_re_rotate)
			base->small_re_rotate = -1;
		else
			base->small_rotate = -1;
	}
}

static void	steps_to_small(t_base *base, char stack_name)
{
	t_stack *stack;
	int		flag;

	if (stack_name == 'a')
		stack = base->a;
	else
		stack = base->b;
	flag = 1;
	if (stack)
	{
		steps_to_start(base, stack_name, flag);
		steps_to_end(base, stack_name, flag);
		if (base->big_rotate <= base->big_re_rotate)
			base->big_re_rotate = -1;
		else
			base->big_rotate = -1;
	}
}

void	steps_counter(t_base *base, char stack_name)
{
	t_stack *stack;

	if (stack_name == 'a')
		stack = base->a;
	else
		stack = base->b;
	steps_to_small(base, 'b');
	steps_to_big(base, 'b');
	if (base->big_rotate != -1 && (base->big_rotate >= base->small_rotate &&
		base->big_rotate >= base->small_re_rotate))
		base->big_rotate = -1;
	else if (base->big_re_rotate != -1 && (base->big_re_rotate >= base->small_rotate &&
		base->big_re_rotate >= base->small_re_rotate))
		base->big_re_rotate = -1;
	else if (base->small_rotate != -1 && (base->small_rotate >= base->big_rotate &&
		base->small_rotate >= base->big_re_rotate))
		base->small_rotate = -1;
	else if (base->small_re_rotate != -1 && (base->small_re_rotate >= base->big_rotate &&
		base->small_re_rotate >= base->big_re_rotate))
		base->small_re_rotate = -1;	
}
