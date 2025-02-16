/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/01/25 10:52:26 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_before_last(t_stack *a)
{
	while (a->next->next != NULL)
	{
		a = a->next;
	}
	return (a);
}

t_stack	*find_max(t_stack *a)
{
	t_stack	*max;

	if (!a)
		return (NULL);
	max = a;
	a = a->next;
	while (a)
	{
		if (a->nbr > max->nbr)
			max = a;
		a = a->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *a)
{
	t_stack	*min;

	if (!a)
		return (NULL);
	min = a;
	a = a->next;
	while (a)
	{
		if (a->nbr < min->nbr)
			min = a;
		a = a->next;
	}
	return (min);
}

int	stack_len(t_stack *a)
{
	int		count;
	t_stack	*cur;

	count = 0;
	cur = a;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void	ft_clear_list(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

	if (!a || !*a)
		return ;
	current = *a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*a = NULL;
}
