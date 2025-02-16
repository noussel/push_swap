/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:09 by nel-khad          #+#    #+#             */
/*   Updated: 2025/01/25 10:54:12 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_stack **a, int n, char **argv)
{
	t_stack	*cur;

	cur = *a;
	while (cur)
	{
		if (cur->nbr == n)
		{
			ft_clear_list(a);
			ft_free(argv);
			error();
		}
		cur = cur->next;
	}
}

void	check_input(char **argv, t_stack **a)
{
	int	i;
	int	j;

	if (!argv)
		error();
	i = 0;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-') && (argv[i][j
					+ 1] < '0' || argv[i][j + 1] > '9'))
				error_free(argv, a);
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') && (argv[i][j
					+ 1] == '+' || argv[i][j + 1] == '-'))
				error_free(argv, a);
			else if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& (argv[i][j] != '+' && argv[i][j] != '-'))
				error_free(argv, a);
			j++;
		}
		i++;
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *ch_n)
{
	while (ch_n != (*a) && ch_n->target != (*b))
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *ch_n)
{
	while (ch_n != (*a) && ch_n->target != (*b))
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

int	str_comp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);
	else
		return (0);
}
