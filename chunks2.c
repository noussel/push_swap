/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/07 15:33:23 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortt_stack(t_stack **a, t_stack **b)
{
	int		*array;
	int		len;
	t_stack	*cur;
	int		i;

	*b = NULL;
	i = 0;
	cur = *a;
	len = stack_len(*a);
	array = malloc(sizeof(int) * (len));
	if (!array)
		return ;
	while (cur)
	{
		array[i] = cur->nbr;
		i++;
		cur = cur->next;
	}
	sort_array(array, len);
	set_index(*a, array, len);
	algo(a, b, len);
	free(array);
	push_to_a(a, b);
}

void	print_stack(t_stack *aa)
{
	t_stack	*a;

	a = aa;
	while (a)
	{
		printf("%d \n", a->nbr);
		a = a->next;
	}
}

int	find_min_position(t_stack *a, t_stack *min)
{
	if (!a)
		return (-1);
	set_position(a);
	while (a)
	{
		if (a == min)
			return (a->pos);
		a = a->next;
	}
	return (-1);
}

void	sort_four_or_mor(t_stack **a, t_stack **b)
{
	int	min_pos;

	while (stack_len(*a) > 3)
	{
		min_pos = find_min_position(*a, find_min(*a));
		while (min_pos > 0 && stack_len(*a) > 3)
		{
			if (min_pos >= stack_len(*a) / 2)
				rra(a);
			else
				ra(a);
			min_pos = find_min_position(*a, find_min(*a));
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
