/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_retate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/07 11:48:53 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_retat(t_stack **a)
{
	t_stack	*b_last;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = ft_last(*a);
	b_last = ft_before_last(*a);
	b_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_stack **b)
{
	rev_retat(b);
	ft_putstr("rrb\n");
}

void	rra(t_stack **a)
{
	rev_retat(a);
	ft_putstr("rra\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_retat(b);
	rev_retat(a);
	ft_putstr("rrr\n");
}
