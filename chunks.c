/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/02 13:02:07 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk(int len)
{
	int	chunk;

	if (len < 400)
		chunk = 23;
	else
		chunk = 40;
	return (chunk);
}

void	set_index(t_stack *a, int array[], int len)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < len)
		{
			if (a->nbr == array[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	get_next_pos(t_stack **a, int chunk, int len, int j)
{
	t_stack	*cur;
	int		i;

	cur = *a;
	len = stack_len(*a);
	i = 0;
	while (i < len)
	{
		if (cur->index < j || cur->index <= chunk + j)
			break ;
		i++;
		cur = cur->next;
	}
	while (i > 0)
	{
		if (i < len / 2)
			ra(a);
		else
			rra(a);
		i--;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	*sort_array(int *array, int len)
{
	int	swp;
	int	i;
	int	temp;

	swp = 1;
	while (swp)
	{
		swp = 0;
		i = 0;
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swp = 1;
			}
			i++;
		}
	}
	return (array);
}
