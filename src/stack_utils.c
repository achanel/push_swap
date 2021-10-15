/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:09:54 by achanel           #+#    #+#             */
/*   Updated: 2021/10/15 12:27:56 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_new(int number)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(struct s_stack));
	if (!stack)
		return (NULL);
	stack->number = number;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

void	stack_add_back(t_stack **stack, int number)
{
	t_stack	*start;
	t_stack	*tmp;

	tmp = add_new(number);
	if (!(*stack))
	{
		(*stack) = tmp;
		return ;
	}
	start = (*stack);
	while (start->next)
		start = start->next;
	start->next = tmp;
	tmp->prev = start;
}

int	stack_len(t_stack *stack)
{
	t_stack	*tmp;
	int		len;

	if (!stack)
		return (0);
	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	find_mid_index(t_stack *stack)
{
	t_stack	*tmp;
	int		mid;

	tmp = stack;
	mid = tmp->index;
	while (tmp)
	{
		if (tmp->index > mid)
			mid = tmp->index;
		tmp = tmp->next;
	}
	return (mid - 2);
}
