/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/01/25 09:51:26 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	invalid_input(char **s)
{
	if (is_duplicat(s))
		return (1);
	return (0);
}

void	check_top_a(t_stack **a, t_stack *ch_n)
{
	while (*a != ch_n)
	{
		if (ch_n->up_down)
			ra(a);
		else
			rra(a);
	}
}

void	check_top_b(t_stack **b, t_stack *ch_n)
{
	while (*b != ch_n)
	{
		if (ch_n->up_down)
			rb(b);
		else if (!(ch_n->up_down))
			rrb(b);
	}
}

void	set_position(t_stack *a)
{
	int		i;
	int		len;
	t_stack	*cur;

	cur = a;
	len = 0;
	i = 0;
	len = stack_len(a);
	while (cur)
	{
		cur->pos = i;
		if (i < len / 2)
			cur->up_down = 1;
		else
			cur->up_down = 0;
		cur = cur->next;
		i++;
	}
}

void	put_min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->up_down)
			ra(a);
		else
			rra(a);
	}
}
