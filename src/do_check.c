/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:10:10 by achanel           #+#    #+#             */
/*   Updated: 2021/10/15 13:22:16 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_number(char *arg)
{
	int	i;

	i = 0;
	if ((ft_strlen(arg) == 1 && arg[i] == ' ') || (ft_strlen(arg) == 0))
		push_swap_error();
	while (arg[i])
	{
		if (arg[i] != ' ')
			return ;
		i++;
	}
	push_swap_error();
}

void	check_int(char *arg)
{
	int		i;
	long	digit;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
			push_swap_error();
		i++;
	}
	digit = ft_atoi(arg);
	if (digit >= 2147483647 || digit <= -217483648)
		push_swap_error();
}

t_stack	*check_stack(t_base *base)
{
	int		i;
	int		j;
	char	**str;
	t_stack	*first;

	i = 0;
	first = NULL;
	while (base->av[++i])
	{
		j = 0;
		check_number(base->av[i]);
		str = ft_split(base->av[i], ' ');
		while (str[j])
		{
			check_int(str[j]);
			stack_add_back(&first, ft_atoi(str[j]));
			free(str[j]);
			j++;
		}
		free(str);
	}
	return (first);
}
