/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:41:23 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 16:38:32 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_sorter(t_base *base)
{
	if (stack_len(base, 'a') <= 5)
		short_solver(base);
	else
	{
		start_sort(base);
		// final_sort(base);
	}
	printf ("%ld\n", base->a->num);
	printf ("%ld\n", base->a->next->num);
	printf ("%ld\n", base->a->next->next->num);
	printf ("%ld\n", base->a->next->next->next->num);
	printf ("%ld\n", base->a->next->next->next->next->num);
	printf ("%ld\n", base->a->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->next->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->next->next->next->next->next->next->next->num);
	// printf ("%ld\n", base->a->next->next->next->next->next->next->next->next->next->next->next->next->next->next->num);
}

static t_base	*new_base(t_base *base)
{
	base = malloc(sizeof(t_base));
	if (!base)
		exit(-1);
	base->a = NULL;
	base->b = NULL;
	base->after_rotate = 0;
	base->base_flag = 0;
	base->biggest = 0;
	base->middle = 0;
	base->smallest = 0;
	base->big_rotate = 0;
	base->small_rotate = 0;
	base->big_re_rotate = 0;
	base->small_re_rotate = 0;
	base->flag_big = 0;
	base->flag_small = 0;
	return (base);
}

static void	push_swap(t_base *base, char **av)
{
	check_stack(base, av);
	if (!is_sorted(base))
	{
		stack_sorter(base);
		return ;
	}
}

int	main(int ac, char **av)
{
	t_base	*base;

	base = NULL;
	if (ac < 2)
		return (1);
	base = new_base(base);
	push_swap(base, av);
	free_base(base);
	return (0);
}
