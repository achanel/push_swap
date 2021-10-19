/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:10:10 by achanel           #+#    #+#             */
/*   Updated: 2021/10/16 16:22:15 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_ps(const char *str)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		if ((((res * 10) + (*str - '0')) < res) && (neg == 1))
			return (-1);
		else if ((((res * 10) + (*str - '0')) < res) && (neg == -1))
			return (0);
		res = (res * 10) + *str - '0';
		++str;
	}
	res *= neg;
	return (res);
}

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
	digit = ft_atoi_ps(arg);
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
			stack_add_back(&first, ft_atoi_ps(str[j]));
			free(str[j]);
			j++;
		}
		free(str);
	}
	return (first);
}
