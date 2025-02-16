/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/09 15:40:38 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	if (invalid_input(argv))
	{
		ft_clear_list(a);
		ft_free(argv);
		error();
	}
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		check_dup(a, n, argv);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_clear_list(a);
			ft_free(argv);
			error();
		}
		add_node(a, (int)n);
		i++;
	}
}

void	init_node_a(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	find_target(a, b);
	mov_count(a, b);
	get_cheapest(a);
}

void	init_node_b(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	find_target_b(a, b);
}

// target of a in b
// closet smaller
void	find_target(t_stack *a, t_stack *stack_b)
{
	long	min;
	t_stack	*b;
	t_stack	*target;

	while (a)
	{
		min = LONG_MIN;
		b = stack_b;
		while (b)
		{
			if (a->nbr > b->nbr && b->nbr > min)
			{
				min = b->nbr;
				target = b;
			}
			b = b->next;
		}
		if (min == LONG_MIN)
			a->target = find_max(stack_b);
		else
			a->target = target;
		a = a->next;
	}
}

// target of b in a
// closet bigger
void	find_target_b(t_stack *stack_a, t_stack *b)
{
	long	max;
	t_stack	*a;
	t_stack	*target;

	while (b)
	{
		max = LONG_MAX;
		a = stack_a;
		while (a)
		{
			if (a->nbr > b->nbr && a->nbr < max)
			{
				max = a->nbr;
				target = a;
			}
			a = a->next;
		}
		if (max == LONG_MAX)
			b->target = find_min(stack_a);
		else
			b->target = target;
		b = b->next;
	}
}
