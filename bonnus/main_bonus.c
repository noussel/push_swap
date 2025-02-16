/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/07 16:39:53 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	choose_move(char *s, t_stack **a, t_stack **b)
{
	if (str_comp(s, "sa\n"))
		sa(a);
	else if (str_comp(s, "sb\n"))
		sb(b);
	else if (str_comp(s, "ss\n"))
		ss(a, b);
	else if (str_comp(s, "ra\n"))
		ra(a);
	else if (str_comp(s, "rb\n"))
		rb(b);
	else if (str_comp(s, "rr\n"))
		rr(a, b);
	else if (str_comp(s, "rra\n"))
		rra(a);
	else if (str_comp(s, "rrb\n"))
		rrb(b);
	else if (str_comp(s, "rrr\n"))
		rrr(a, b);
	else if (str_comp(s, "pa\n"))
		pa(a, b);
	else if (str_comp(s, "pb\n"))
		pb(a, b);
	else
		return (1);
	return (0);
}

void	check_push_swap(t_stack **a, t_stack **b, char **argv)
{
	char	*move;
	int		flag;

	move = get_next_line(0, 0);
	while (move != NULL)
	{
		flag = choose_move(move, a, b);
		free(move);
		if (flag == 1)
		{
			move = get_next_line(0, 1);
			error_free(argv, a);
		}
		move = get_next_line(0, 0);
	}
	return ;
}

void	check_space(char *argv)
{
	if (!argv)
		error();
	is_space(argv);
}

void	resume_main(char **argv, t_stack **a, t_stack **b)
{
	char	**argv_buff;
	int		i;

	i = 1;
	while (argv[i])
		check_space(argv[i++]);
	i = 1;
	while (argv[i])
	{
		argv_buff = ft_split(argv[i]);
		if (!argv_buff)
			error_free(argv_buff, a);
		if (ft_strlen(argv[i]) > 11 && ft_atoi(argv[i]) == -1 && diff(argv[i]))
			error_free(argv_buff, a);
		check_input(argv_buff, a);
		init_stack_a(a, argv_buff);
		ft_free(argv_buff);
		argv_buff = NULL;
		i++;
	}
	check_push_swap(a, b, argv_buff);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2 && !argv[1][0])
		error();
	else if (argc >= 2)
		resume_main(argv, &a, &b);
	if (stack_sorted(a) && b == NULL)
	{
		write(1, "OK\n", 3);
	}
	else if (!(stack_sorted(a)) || b != 0)
		write(1, "KO\n", 3);
	ft_clear_list(&a);
	ft_clear_list(&b);
	return (0);
}
