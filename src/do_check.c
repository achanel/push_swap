/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:10:10 by achanel           #+#    #+#             */
/*   Updated: 2021/10/05 14:54:56 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicates(t_base *base)
{
	t_stack	*x;
	t_stack	*y;

	x = base->a;
	while (x != base->a->prev)
	{
		y = x->next;
		while (y != base->a)
		{
			if (x->num == y->num)
				push_swap_error(base);
			y = y->next;
		}
		x = x->next;
	}
}

static long	int_maker(char *str)
{
	int		neg;
	long	res;
	int		len;

	neg = 1;
	res = 0;
	len = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str == '0')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - '0';
		++str;
		len++;
	}
	// if (len > 10)
	// 	push_swap_error(base);
	res *= neg;
	return (res);
}

static void	push_swap_atoi(t_base *base, char **av)
{
	int		i;
	int		k;
	long	integer;
	char	*str;

	i = 1;
	k = 0;
	str = av[i];
	while (str)
	{
		while (*str)
		{
			while (*str && *str == ' ' && !(k = 0))
				str++;
			while (*(str + k) && (*(str + k) == '+' || *(str + k) == '-' || ft_isdigit(*(str + k))))
				k++;
			if (!*str)
				break ;
			integer = int_maker(str);
			if (integer > 2147483647 || integer < -2147483648)
				push_swap_error(base);
			stack_add_back(base, 'a', integer);
			str += k;
		}
		str = av[++i];
	}
}

static void	string_parsing(t_base *base, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) || av[i][j] == ' ')
				j++;
			else
				push_swap_error(base);
		}
		j = 0;
		i++;
	}
}

int	check_stack(t_base *base, char **av)
{

	string_parsing(base, av);
	push_swap_atoi(base, av);
	check_duplicates(base);
	return (0);
}
