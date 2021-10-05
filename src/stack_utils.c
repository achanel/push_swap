/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:09:54 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 13:18:19 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_new(t_base *base, t_stack **start, int nm)
{
	*start = ft_calloc(sizeof(t_stack), sizeof(t_stack));
	if (!start)
		push_swap_error(base);
	(*start)->next = *start;
	(*start)->prev = *start;
	(*start)->num = nm;
	// (*start)->flag = fl;
	// (*start)->order = or;
}

void	stack_add_back(t_base *base, char stack_name, int number)
{
	t_stack	**start;
	t_stack	*tmp;

	if (stack_name == 'a')
		start = &base->a;
	else
		start = &base->b;
	if (!*start)
		add_new(base, start, number);
	else
	{
		tmp = ft_calloc(sizeof(t_stack), sizeof(t_stack));
		if (!tmp)
			push_swap_error(base);
		tmp->next = *start;
		tmp->prev = (*start)->prev;
		(*start)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->num = number;
	}
}

void	stack_add_front(t_base *base, char stack_name, int nm)
{
	t_stack	**start;
	t_stack	*tmp;

	if (stack_name == 'a')
		start = &base->a;
	else
		start = &base->b;
	if (!*start)
		add_new(base, start, nm);
	else
	{
		tmp = ft_calloc(sizeof(t_stack), sizeof(t_stack));
		if (!tmp)
			push_swap_error(base);
		tmp->next = *start;
		tmp->prev = (*start)->prev;
		(*start)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->num = nm;
		// tmp->flag = fl;
		// tmp->order = or;
		*start = (*start)->prev;
	}
}

void	stack_del_top(t_base *base, char stack_name)
{
	t_stack	**start;
	t_stack	*tmp;

	if (stack_name == 'a')
		start = &base->a;
	else
		start = &base->b;
	if (*start)
	{
		if ((*start)->next == *start)
		{
			free (*start);
			*start = NULL;
		}
		else
		{
			tmp = *start;
			(*start) = (*start)->next;
			tmp->prev->next = (*start);
			(*start)->prev = tmp->prev;
			free (tmp);
		}
	}
}

int	stack_len(t_base *base, char stack_name)
{
	t_stack *end;
	t_stack	*tmp;
	int		len;

	len = 1;
	if (stack_name == 'a')
		tmp = base->a;
	else
		tmp = base->b;
	if (tmp)
	{
		if (stack_name == 'a')
			end = base->a->prev;
		else
			end = base->b->prev;
	}
	while (tmp)
	{
		if (tmp == end)
			break ;
		len++;
		tmp = tmp->next;
	}
	return (len);
}