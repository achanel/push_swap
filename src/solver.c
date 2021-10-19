/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:47:47 by achanel           #+#    #+#             */
/*   Updated: 2021/10/16 12:30:29 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_b(t_stack *stack, int index)
{
	int	position_b;

	position_b = 1;
	while (stack->index != index)
	{
		position_b++;
		stack = stack->next;
	}
	return (position_b);
}

int	position_a(t_stack *stack, int index)
{
	t_stack	*tmp;
	int		small;
	int		optimal;
	int		next;
	int		prev;

	optimal = 1;
	small = find_smallest_index(stack);
	if (index < small)
		return (position_b(stack, small));
	tmp = stack->next;
	prev = stack->index;
	next = tmp->index;
	while (1)
	{
		optimal++;
		if (prev < index && next > index)
			return (optimal);
		prev = tmp->index;
		if (!tmp->next)
			tmp = stack;
		else
			tmp = tmp->next;
		next = tmp->index;
	}
}

int	optimal_move(int total_sum, t_steps *steps)
{
	int	i;

	i = steps->ra;
	if (steps->ra > steps->rb)
		i = steps->rb;
	while (i)
	{
		total_sum--;
		i--;
	}
	i = steps->rra;
	if (steps->rra > steps->rrb)
		i = steps->rrb;
	while (i)
	{
		total_sum--;
		i--;
	}
	return (total_sum);
}

int	ft_steps_count(t_stack *stack_a, t_stack *stack_b,
		t_steps *steps, int index)
{
	int		total_sum;

	new_steps(steps);
	steps->len = stack_len(stack_b);
	steps->index = position_b(stack_b, index);
	if (steps->len / 2 >= steps->index)
		steps->rb = steps->index - 1;
	else if (steps->len > 1)
		steps->rrb = steps->len - steps->index + 1;
	steps->len = stack_len(stack_a);
	steps->index = position_a(stack_a, index);
	if (steps->len / 2 >= steps->index)
		steps->ra = steps->index - 1;
	else
		steps->rra = steps->len - steps->index + 1;
	total_sum = steps->ra + steps->rb + steps->rra + steps->rrb;
	return (optimal_move(total_sum, steps));
}

void	sort_b(t_base *base, t_steps *steps)
{
	int		steps_count;
	int		min;
	t_stack	*stack;
	t_stack	*steps_stack;

	min = -1;
	stack = base->b;
	while (stack)
	{
		steps_count = ft_steps_count(base->a, base->b, steps, stack->index);
		if (min == -1 || steps_count <= min)
		{
			min = steps_count;
			steps_stack = stack;
		}
		stack = stack->next;
	}
	min = ft_steps_count(base->a, base->b, steps, steps_stack->index);
	sort_b_helper(&(base->a), &(base->b), steps);
}
