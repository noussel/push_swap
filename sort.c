/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/01/25 10:51:33 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *a)
{
	t_stack	*cur;

	if (!a)
		return (-1);
	cur = a;
	while (cur->next)
	{
		if (cur->nbr > cur->next->nbr)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	sort_three(t_stack **a)
{
	if (((*a)->nbr > (*a)->next->nbr) && ((*a)->nbr > (*a)->next->next->nbr))
		ra(a);
	else if (((*a)->next->nbr > (*a)->nbr)
		&& ((*a)->next->nbr > (*a)->next->next->nbr))
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
	return ;
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (len-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (len-- > 3 && !stack_sorted(*a))
	{
		init_node_a(*a, *b);
		move_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_node_b(*a, *b);
		move_to_a(a, b);
	}
	set_position(*a);
	put_min_on_top(a);
}
