/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/02 13:33:41 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicat(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i + 1])
	{
		j = i + 1;
		while (s[j])
		{
			if (str_comp(s[i], s[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	is_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		error();
	return ;
}

void	error_free(char **argv, t_stack **a)
{
	write(2, "Error\n", 6);
	if (argv)
		ft_free(argv);
	if (*a)
		ft_clear_list(a);
	exit(1);
}
