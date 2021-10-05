/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:43:24 by achanel           #+#    #+#             */
/*   Updated: 2021/09/17 11:43:25 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_base *base)
{
	if (base->a)
		base->a = base->a->next;
	write(1, "ra\n", 3);
}

void	rotate_b(t_base *base)
{
	if (base->b)
		base->b = base->b->next;
	write(1, "rb\n", 3);
}

void	rotate_rr(t_base *base)
{
	rotate_a(base);
	rotate_b(base);
	write (1, "rr\n", 3);
}

void	reverse_rotate_a(t_base *base)
{
	if (base->a)
		base->a = base->a->prev;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_base *base)
{
	if (base->b)
		base->b = base->b->prev;
	write(1, "rrb\n", 4);
}
