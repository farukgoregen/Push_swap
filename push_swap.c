/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:13:10 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/01 13:04:27 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_list_free(t_stack **heap)
{
	t_stack	*temp;

	while (*heap)
	{
		temp = (*heap)->next;
		free((*heap));
		*heap = temp;
	}
	free(heap);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_add_stack(t_stack **a, char **av, int ac)
{
	t_stack	*new;
	char	**argv;
	int		i;

	i = 0;
	if (ac == 2)
		argv = ft_split(av[1], ' ');
	else
	{
		i = 1;
		argv = av;
	}
	while (argv[i])
	{
		new = ft_lstnews(ft_atoi(argv[i]));
		ft_lstadd_backst(a, new);
		i++;
	}
	ft_index(a);
	if (ac == 2)
	{
		ft_free(argv);
	}
}

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	if (ac < 2)
		return (-1);
	ft_error_av(ac, av);
	a = malloc(sizeof(t_stack *));
	*a = NULL;
	ft_add_stack(a, av, ac);
	if (check_sort(a) == 0)
	{
		ft_list_free(a);
		return (0);
	}
	b = malloc(sizeof(t_stack *));
	*b = NULL;
	input_sort(a, b);
	ft_list_free(a);
	ft_list_free(b);
}
