/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retat_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/01/25 09:28:02 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	retat(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	last = ft_last(*a);
	*a = (*a)->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rb(t_stack **b)
{
	retat(b);
}

void	ra(t_stack **a)
{
	retat(a);
}

void	rr(t_stack **a, t_stack **b)
{
	retat(a);
	retat(b);
}
