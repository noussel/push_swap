/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/07 16:44:12 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}

int	strcomp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
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
