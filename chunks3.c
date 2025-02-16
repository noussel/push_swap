/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/07 15:38:19 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_space(char *argv)
{
	if (!argv)
		error();
	is_space(argv);
}

int	diff(char *s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	rev_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->nbr < a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_rev(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	while ((*a))
	{
		pb(a, b);
		rb(b);
	}
	while (*b)
		pa(a, b);
}
