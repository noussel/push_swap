/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/01/25 09:27:45 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **a)
{
	int	tmp;

	if ((*a)->next == NULL || (*a) == NULL || a == NULL)
		return ;
	tmp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = tmp;
}

void	sa(t_stack **a)
{
	if ((*a)->next == NULL || (*a) == NULL || a == NULL)
		return ;
	swap(a);
}

void	sb(t_stack **b)
{
	if ((*b) == NULL || b == NULL || (*b)->next == NULL)
		return ;
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	if ((*a)->next == NULL || (*a) == NULL || a == NULL)
		return ;
	if ((*b)->next == NULL || (*b) == NULL || b == NULL)
		return ;
	swap(a);
	swap(b);
}
