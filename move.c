/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/01/25 10:50:02 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move needed to set the node and its target on top
void	mov_count(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->up_down && a->target->up_down)
			a->push_cost = max(a->pos, a->target->pos);
		if (!(a->up_down) && !(a->target->up_down))
			a->push_cost = max(len_a - a->pos, len_b - a->target->pos);
		if (!(a->up_down) && a->target->up_down)
			a->push_cost = max(len_a - a->pos, a->target->pos);
		if (a->up_down && !(a->target->up_down))
			a->push_cost = max(a->pos, len_b - a->target->pos);
		a = a->next;
	}
}

// push from a to b
void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*ch_n;

	ch_n = get_cheapest(*a);
	if (ch_n->up_down && ch_n->target->up_down)
		rotate_both(a, b, ch_n);
	else if (!(ch_n->up_down) && !(ch_n->target->up_down))
		rev_rotate_both(a, b, ch_n);
	check_top_a(a, ch_n);
	check_top_b(b, ch_n->target);
	pb(a, b);
}

// push from b to a
void	move_to_a(t_stack **a, t_stack **b)
{
	check_top_a(a, (*b)->target);
	pa(a, b);
}

// finding the cheapest node to move
t_stack	*get_cheapest(t_stack *a)
{
	long	cheap_value;
	t_stack	*cheap_node;

	if (!a)
		return (NULL);
	cheap_value = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheap_value)
		{
			cheap_value = a->push_cost;
			cheap_node = a;
		}
		a = a->next;
	}
	return (cheap_node);
}

void	add_node(t_stack **a, int nbr)
{
	t_stack	*new;
	t_stack	*last;

	new = ft_lstnew(nbr);
	if (!*a)
	{
		*a = new;
		return ;
	}
	last = ft_last(*a);
	last->next = new;
}
