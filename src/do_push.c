/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:41:00 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 13:19:24 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_base *base)
{
	long	s_number;
	// int		s_flag;
	// int		s_order;

	s_number = base->b->num;
	// s_flag = base->b->flag;
	// s_order = base->b->order;
	if (base->b)
	{
		stack_del_top(base, 'b');
		stack_add_front(base, 'a', s_number);
	}
	write(1, "pa\n", 3);
}

void	push_b(t_base *base)
{
	long	s_number;
	// int		s_flag;
	// int		s_order;

	s_number = base->a->num;
	// s_flag = base->a->flag;
	// s_order = base->a->order;
	if (base->a)
	{
		stack_del_top(base, 'a');
		stack_add_front(base, 'b', s_number);
	}
	write(1, "pb\n", 3);
}
