/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:10:30 by achanel           #+#    #+#             */
/*   Updated: 2021/10/15 12:25:02 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->prev;
		while (tmp)
		{
			if (tmp->number == stack->number)
				push_swap_error();
			tmp = tmp->prev;
		}
		stack = stack->next;
	}
}

int	is_sorted(t_stack *stack)
{	
	check_duplicates(stack);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	clear_stack(t_stack **stack)
{
	if ((*stack))
	{
		while ((*stack)->next)
		{
			*stack = (*stack)->next;
			free ((*stack)->prev);
			(*stack)->prev = NULL;
		}
		free ((*stack)->prev);
		(*stack)->prev = NULL;
	}
}

void	free_base(t_base *base)
{
	if (base)
	{
		if (base->a)
			clear_stack(&base->a);
		if (base->b)
			clear_stack(&base->b);
		free (base);
	}
}

int	push_swap_error(void)
{
	write(1, "Error\n", 6);
	exit (1);
	return (0);
}
