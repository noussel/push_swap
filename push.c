/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/01/25 09:14:12 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*head_a;

	if (!*a)
		return ;
	head_a = *a;
	*a = (*a)->next;
	if (!*b)
	{
		*b = head_a;
		(*b)->next = NULL;
	}
	else
	{
		head_a->next = *b;
		*b = head_a;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
