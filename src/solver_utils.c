/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:54:12 by achanel           #+#    #+#             */
/*   Updated: 2021/10/15 12:27:17 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_helper_helper(t_stack **stack_a, t_stack **stack_b,
			t_steps *steps)
{
	if (steps->ra > 0)
	{
		rotate(stack_a, "ra\n");
		steps->ra--;
	}
	else if (steps->rb > 0)
	{
		rotate(stack_b, "rb\n");
		steps->rb--;
	}
	else if (steps->rra > 0)
	{
		reverse_rotate(stack_a, "rra\n");
		steps->rra--;
	}
	if (steps->rrb > 0)
	{
		reverse_rotate(stack_b, "rrb\n");
		steps->rrb--;
	}
}

void	sort_b_helper(t_stack **stack_a, t_stack **stack_b, t_steps *steps)
{
	while (steps->ra || steps->rb || steps->rra || steps->rrb)
	{
		if (steps->ra && steps->rb)
		{
			rr_rotate(stack_a, stack_b, "rr\n");
			steps->ra--;
			steps->rb--;
		}
		else if (steps->rra && steps->rrb)
		{
			rrr_rev_rotate(stack_a, stack_b, "rrr\n");
			steps->rra--;
			steps->rrb--;
		}
		else
			sort_b_helper_helper(stack_a, stack_b, steps);
	}
	if (stack_b)
		push(stack_b, stack_a, "pa\n");
}

void	final_sort(t_stack **stack, t_steps *steps)
{
	new_steps(steps);
	steps->len = stack_len(*stack);
	steps->index = position(*stack, 1);
	if (steps->len / 2 >= steps->index)
		steps->ra = steps->index - 1;
	else if (steps->len > 1)
		steps->rra = steps->len - steps->index + 1;
	sort_b_helper(stack, NULL, steps);
	return ;
}
