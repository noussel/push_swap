/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/07 16:41:52 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				pos;
	struct s_stack	*target;
	int				index;
	int				push_cost;
	int				up_down;

	struct s_stack	*next;
}					t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
ssize_t				ft_strlen(const char *str);
int					ft_strchr(const char *s);
char				*ft_substr(char const *s, unsigned int start, ssize_t len);
char				*get_next_line(int fd, int flag);

// int invalid_input(char **s);
// int is_duplicat(char **s);
// int is_digit(char *s);
void				init_stack_a(t_stack **a, char *argv[]);
void				ft_clear_list(t_stack **a);
long				ft_atoi(char *s);
void				add_node(t_stack **a, int nbr);
t_stack				*ft_last(t_stack *a);
t_stack				*ft_lstnew(int i);
t_stack				*find_max(t_stack *a);
t_stack				*find_min(t_stack *a);
t_stack				*ft_before_last(t_stack *a);
t_stack				*get_cheapest(t_stack *a);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
int					is_digit(char *s);
void				sb(t_stack **b);
void				sa(t_stack **a);
int					diff(char *s);
int					str_comp(char *s1, char *s2);
void				rb(t_stack **b);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				rrb(t_stack **b);
long				ft_atoi(char *s);
void				ft_free(char **s);
void				ft_putstr(char *s);
char				**ft_split(char *s);
int					invalid_input(char **s);
void				sort_three(t_stack **a);
void				is_space(char *s);
void				check_input(char **argv, t_stack **a);
void				set_position(t_stack *a);
void				ft_clear_list(t_stack **a);
void				rrr(t_stack **a, t_stack **b);
void				add_node(t_stack **a, int nbr);
void				mov_count(t_stack *a, t_stack *b);
void				error_free(char **argv, t_stack **a);
void				sort_stack(t_stack **a, t_stack **b);
void				init_stack_a(t_stack **a, char **argv);
void				check_top_b(t_stack **b, t_stack *ch_n);
void				find_target(t_stack *a, t_stack *stack_b);
void				rev_rotate_both(t_stack **a, t_stack **b, t_stack *ch_n);
void				rotate_both(t_stack **a, t_stack **b, t_stack *ch_n);
void				find_target_b(t_stack *stack_a, t_stack *b);
void				check_top_a(t_stack **a, t_stack *ch_n);
char				**fil_string(char *s, char *argv[]);
void				check_dup(t_stack **a, int n, char **argv);
void				move_to_b(t_stack **a, t_stack **b);
void				move_to_a(t_stack **a, t_stack **b);
void				init_node_a(t_stack *a, t_stack *b);
void				init_node_b(t_stack *a, t_stack *b);
void				ss(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				put_min_on_top(t_stack **a);
int					stack_sorted(t_stack *a);
int					is_duplicat(char **s);
int					stack_len(t_stack *a);
int					max(int a, int b);
void				error(void);

#endif
