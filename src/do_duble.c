/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_duble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:41:07 by achanel           #+#    #+#             */
/*   Updated: 2021/10/14 12:19:46 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_swap(t_stack **stack, t_stack **dst, char *str)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (*dst == NULL || (*dst == NULL))
		return ;
	swap(stack, 0);
	swap(dst, str);
}

void	rr_rotate(t_stack **stack, t_stack **dst, char *str)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (*dst == NULL || (*dst == NULL))
		return ;
	rotate(stack, 0);
	rotate(dst, str);
}

void	rrr_rev_rotate(t_stack **stack, t_stack **dst, char *str)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (*dst == NULL || (*dst == NULL))
		return ;
	reverse_rotate(stack, 0);
	reverse_rotate(dst, str);
}
