/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:41:07 by achanel           #+#    #+#             */
/*   Updated: 2021/09/17 11:41:08 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_base *base)
{
	long	tmp;

	if (base->a && base->a->next != base->a)
	{
		tmp = base->a->num;
		base->a->num = base->a->next->num;
		base->a->next->num = tmp;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_base *base)
{
	long	tmp;

	if (base->b && base->b->next != base->b)
	{
		tmp = base->b->num;
		base->b->num = base->b->next->num;
		base->b->next->num = tmp;
	}
	write(1, "sb\n", 3);
}

void	swap_ss(t_base *base)
{
	swap_a(base);
	swap_b(base);
	write(1, "ss\n", 3);
}

void	reverse_rotate_rrr(t_base *base)
{
	reverse_rotate_a(base);
	reverse_rotate_b(base);
	write(1, "rrr\n", 4);
}
