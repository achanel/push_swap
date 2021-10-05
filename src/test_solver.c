
void	final_sort(t_base *base)
{
	int	i;

	i = 0;
	base->middle = (stack_len(base, 'a') - base->next_elem) / 2 + base->next_elem;
	while (base->a->order != 1)
	{
		if (base->a->order <= base->middle)
			push_b(base);
		else
		{
			rotate_a(base);
			i++;
		}
	}
	while (base->a->prev->order != (base->next_elem - 1))
	{
		if (base->a->order == base->next_elem)
			reverse_rotate_a(base);
		else
			reverse_rotate_rrr(base);
	}
	sort_b(base);
}

void	sort_a(t_base *base)
{
	int	i;

	if (base->a->flag > 0)
	{
		i = base->a->flag;
		while (base->a->flag == i)
		{
			if (base->a->order == base->next_elem)
			{
				rotate_a(base);
				base->next_elem++;
			}
			else
				push_b(base);
		}
		if (stack_len(base, 'b'))
		{
			find_midle(base, 'b');
			sort_b(base);
		}
	}
}

void	sort_b(t_base *base)
{
	int	i;
	int	len_b;

	i = 0;
	len_b = stack_len(base, 'b');
	// printf ("len%d\n", len_b);
	base->biggest = base->middle;
	base->middle = (base->biggest - base->next_elem) / 2 + base->next_elem;
	// printf ("big%d\n", base->biggest);
	// printf ("mid%d\n", base->middle);
	// printf ("bnum%d\n", base->b->order);
	// printf ("bnum%d\n", base->b->next->order);
	// printf ("bnum%d\n", base->b->next->next->order);
	// printf ("bnum%d\n", base->b->next->next->next->order);
	while (i < stack_len(base, 'b'))
	{
		// printf ("ord%d\n", base->b->order);
		// printf ("mid%d\n", base->middle);
		if (base->b->order > base->middle)
		{
			base->b->flag = base->base_flag;
			push_a(base);
		}
		else
		{
			if (base->b->order == base->next_elem)
			{
				push_a(base);
				rotate_a(base);
				base->next_elem++;
			}
			else
				rotate_b(base);
		}
		i++;
	}
	if (len_b > 1)
	{
		base->base_flag++;
		sort_b(base);
	}
	sort_a(base);
}

void	start_sort(t_base *base)
{
	int	i;

	i = 0;
	base->next_elem = 1;
	do_big_small(base, 'a');
	find_midle(base, 'a');
	base->middle = stack_len(base, 'a') / 2 + 1;
	// printf ("mid%d\n", base->middle);
	// printf ("big%d\n", base->biggest);
	// printf ("small%d\n", base->smallest);
	// printf ("max%d\n", base->stack_len);
	while (i <= base->stack_len)
	{
		if (base->a->order <= base->middle)
			push_b(base);
		else
			rotate_a(base);
		i++;
	}
	// if (base->a->order <= base->middle)
	// 	push_b(base);
	sort_b(base);
}