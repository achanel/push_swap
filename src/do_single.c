/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_single.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:41:00 by achanel           #+#    #+#             */
/*   Updated: 2021/10/14 12:34:43 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, t_stack **dst, char *str)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	if (!(*dst))
	{
		*dst = tmp;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
		write(1, str, 3);
		return ;
	}
	(*dst)->prev = tmp;
	(*dst)->prev->next = *dst;
	*dst = (*dst)->prev;
	(*dst)->prev = NULL;
	write(1, str, 3);
}

void	swap(t_stack **stack, char *str)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if ((*stack)->next)
		(*stack)->next->prev = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
	write(1, str, 3);
}

void	rotate(t_stack **stack, char *str)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!(*stack)->prev)
		while (tmp->next)
			tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp = (*stack)->next;
	(*stack)->next->prev = NULL;
	(*stack)->next = NULL;
	*stack = tmp;
	write(1, str, 3);
}

void	reverse_rotate(t_stack **stack, char *str)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!(*stack)->prev)
		while (tmp->next)
			tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = (*stack);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = tmp;
	write(1, str, 4);
}
