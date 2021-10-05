/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_big_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:16:37 by achanel           #+#    #+#             */
/*   Updated: 2021/10/04 10:16:49 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_big(t_base *base, char stack_name)
{
	t_stack	*stack;
	t_stack	*tmp;
	t_stack	*end;

	if (stack_name == 'a')
		stack = base->a;
	else
		stack = base->b;
	tmp = stack;
	if (stack_name == 'a')
		end = base->a->prev;
	else
		end = base->b->prev;
	base->biggest = tmp->num;
	while (1)
	{
		if (tmp->num > base->biggest)
			base->biggest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	do_small(t_base *base, char	stack_name)
{
	t_stack	*stack;
	t_stack	*tmp;
	t_stack	*end;

	if (stack_name == 'a')
		stack = base->a;
	else
		stack = base->b;
	tmp = stack;
	end = tmp->prev;
	base->smallest = tmp->num;
	while (1)
	{
		if (tmp->num < base->smallest)
			base->smallest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	do_big_small(t_base *base, char	stack_name)
{
	do_big(base, stack_name);
	do_small(base, stack_name);
}
