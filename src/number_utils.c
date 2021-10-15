/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:49:13 by achanel           #+#    #+#             */
/*   Updated: 2021/10/14 15:13:38 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_index(t_stack **stack, long *array)
{
	long	*tmp;
	t_stack	*tmp_stack;
	int		size;
	int		i;

	size = stack_len(*stack);
	tmp = sort_array(array, size);
	tmp_stack = (*stack);
	while (tmp_stack)
	{
		i = 0;
		while (tmp[i] || size > i)
		{
			if (tmp_stack->number == tmp[i])
				tmp_stack->index = i + 1;
			i++;
		}
		tmp_stack = tmp_stack->next;
	}
}

long	*array_to_stack(t_stack *stack)
{
	int		i;
	long	*array;

	check_duplicates(stack);
	array = (long *)malloc(sizeof(long) * stack_len(stack));
	if (!array)
		push_swap_error();
	i = 0;
	while (stack)
	{
		array[i] = stack->number;
		stack = stack->next;
		i++;
	}
	return (array);
}

long	*sort_array(long *array, int size)
{
	long	tmp;
	int		i;
	int		flag;

	tmp = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				flag = 1;
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
			i++;
		}
	}
	return (array);
}

int	find_smallest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index < index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

int	do_small(t_stack *stack)
{
	int	small;

	small = stack->number;
	stack = stack->next;
	while (stack)
	{
		if (stack->number < small)
			small = stack->number;
		stack = stack->next;
	}
	return (small);
}
