/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/11 09:07:08 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main()
// {
//     t_stack *list;
//     list = ft_lstnew(10);
//     list->next = ft_lstnew(5);
//     list->next->next = ft_lstnew(2);

//     sb(&list);
//     printf("%d\n", list->nbr);
//     // exit(0)
//     printf("%d\n", list->next->nbr);
//     printf("%d\n", list->next->next->nbr);
//     rb(&list);
//     printf("%d\n", list->nbr);
//     printf("%d\n", list->next->nbr);
//     printf("%d\n", list->next->next->nbr);
// }

void	algo(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = get_chunk(len);
	while (*a)
	{
		if ((*a)->index < i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b);
			if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
				sb(b);
			i++;
		}
		else
			get_next_pos(a, chunk, stack_len(*a), i);
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*max;

	set_position(*b);
	max = find_max(*b);
	while (stack_len(*b) > 0)
	{
		if (*b == max)
		{
			pa(a, b);
			if (stack_len(*b) > 0)
			{
				set_position(*b);
				max = find_max(*b);
			}
		}
		else
		{
			if (max->pos <= stack_len(*b) / 2)
				rb(b);
			else
				rrb(b);
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else if (stack_len(*a) <= 5)
			sort_four_or_mor(a, b);
		else if (rev_sorted(*a))
			sort_rev(a, b);
		else
			sortt_stack(a, b);
	}
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
		i++;
	}
	sort(a, b);
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
	ft_clear_list(&a);
	ft_clear_list(&b);
	return (0);
}
