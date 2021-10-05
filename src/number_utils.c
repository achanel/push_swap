/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:49:13 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 16:29:14 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(long *array, t_base *base)
{
	long	tmp;
	int		i;
	// int		j;
	t_stack	*stack;

	i = 0;
	tmp = 0;
	stack = base->a;
	while (i < base->stack_len - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	// i = 0;
	// while (i < stack_len(base, 'a'))
	// {
	// 	j = 0;
	// 	while (j < stack_len(base, 'a'))
	// 	{
	// 		if (stack->num == array[j])
	// 			stack->order = j + 1;
	// 		j++;
	// 	}
	// 	printf ("=order %d=", stack->order);
	// 	stack = stack->next;
	// 	i++;
	// }
}

void	find_midle(t_base *base, char stack_name)
{
	long	*array;
	int		i;
	t_stack	*stack;
	int		middle;
	
	i = 0;
	if (stack_name == 'a')
		stack = base->a;
	else
		stack = base->b;
	base->stack_len = stack_len(base, stack_name);
	middle = base->stack_len / 2;
	array = (long*)malloc(sizeof(long) * (base->stack_len + 1));
	if (!array)
		push_swap_error(base);
	while (i < base->stack_len)
	{
		array[i++] = stack->num;
		stack = stack->next;
	}
	sort_array(array, base);
	base->middle = array[middle];
	free (array);
}

// void	do_order(t_base *base)
// {
// 	int		i;
// 	int		j;
// 	long	*array;
// 	t_stack	*stack;

// 	i = 0;
// 	stack = base->a;
// 	array = (long*)malloc(sizeof(long) * (base->stack_len + 1));
// 	if (!array)
// 		push_swap_error(base);
// 	while (i < base->stack_len)
// 	{
// 		array[i] = stack->num;
// 		stack = stack->next;
// 		i++;
// 	}
// 	sort_array(array, base->stack_len);

// }