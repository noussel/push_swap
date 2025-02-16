/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:55:22 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/02 13:33:24 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

int	count_num(char *s)
{
	int	i;
	int	cn;

	i = 0;
	cn = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
			cn++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (cn);
}

void	ft_free(char **s)
{
	int	i;

	if (!s || !*s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

char	**fil_string(char *s, char **argv)
{
	int	i;
	int	u;
	int	j;

	i = 0;
	u = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		j = i;
		while (s[i] && s[i] != ' ')
			i++;
		if (j < i)
		{
			argv[u] = malloc(sizeof(char) * ((i - j) + 1));
			if (!argv[u])
			{
				ft_free(argv);
				return (NULL);
			}
			ft_strncpy(argv[u++], &s[j], (i - j));
		}
	}
	return (argv[u] = NULL, argv);
}

char	**ft_split(char *s)
{
	char	**argv;
	int		cn;

	cn = count_num(s);
	if (!s)
		return (NULL);
	cn = count_num(s);
	if (cn == 0)
		return (NULL);
	argv = malloc(sizeof(char *) * (cn + 1));
	if (!argv)
	{
		ft_free(argv);
		return (NULL);
	}
	argv = fil_string(s, argv);
	return (argv);
}

// int main()
// {
//     int i = 0;
//     char *s = "253 635 823 325";
//     char **ss = ft_split(s);
//     // exit(0);
//     while(ss[i])
//     {
//         printf("%s\n", ss[i]);
//         i++;
//     }
//     ft_free(ss);
// }
