/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:41:23 by achanel           #+#    #+#             */
/*   Updated: 2021/10/14 15:25:41 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_base(t_base *base, int ac, char **av)
{
	base->b = NULL;
	base->biggest = 0;
	base->smallest = 0;
	base->len = 0;
	base->ac = ac;
	base->av = av;
	base->array = NULL;
}

void	new_steps(t_steps *steps)
{
	steps->len = 0;
	steps->ra = 0;
	steps->rb = 0;
	steps->rra = 0;
	steps->rrb = 0;
	steps->index = 0;
}

int	main(int ac, char **av)
{
	t_base	*base;

	if (ac == 1)
		exit(0);
	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
		exit(0);
	new_base(base, ac, av);
	base->a = check_stack(base);
	base->len = stack_len(base->a);
	if (is_sorted(base->a))
		exit(1);
	base->array = array_to_stack(base->a);
	do_index(&base->a, base->array);
	start_sort(base);
	free_base(base);
	return (0);
}
