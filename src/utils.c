/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:10:30 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 16:39:46 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*list;

	if (stack)
	{
		list = stack->next;
		while (list != stack)
		{
			tmp = list;
			list = tmp->next;
			free (tmp);
		}
		free (list);
	}
}

void	free_base(t_base *base)
{
	if (base)
	{
		if (base->a)
			clear_stack(base->a);
		if (base->b)
			clear_stack(base->b);
		free (base);
	}
}

int	is_sorted(t_base *base)
{
	t_stack	*x;
	t_stack	*y;

	x = base->a;
	while (x != base->a->prev)
	{
		y = x->next;
		if (x->num > y->num)
			return (0);
		y = y->next;
		x = x->next;
	}
	return (1);
}

int	push_swap_error(t_base *base)
{
	write(1, "ERROR\n", 6);
	exit (-1);
	free_base(base);
	return (0);
}
