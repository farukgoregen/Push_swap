/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:07:21 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/01 12:25:11 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **a)
{
	t_stack	*list;

	list = *a;
	if (list == NULL)
		return (0);
	while (list->next != NULL)
	{
		if (list->index > list->next->index)
			return (1);
		list = list->next;
	}
	return (0);
}

static void	sort3(t_stack **a)
{
	t_stack	*maxin;

	maxin = max_index(a);
	while (check_sort(a) == 1)
	{
		if (*a == maxin)
			ft_ra(a);
		else if ((*a)->next == maxin)
			ft_rra(a);
		else if ((*a)->index > (*a)->next->index)
			ft_sa(a);
	}
}

static void	sort4(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		size;

	min = min_index(a);
	size = ft_lstsizepush(a);
	while (size == 4)
	{
		if ((*a) == min)
			ft_pb(a, b);
		else if ((*a)->next == min)
			ft_sa(a);
		else if ((*a)->next->next == min)
			ft_ra(a);
		else if ((*a)->next->next->next == min)
			ft_rra(a);
		size = ft_lstsizepush(a);
	}
	sort3(a);
	ft_pa(a, b);
}

static void	sort5(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = min_index(a);
	while ((*b) == NULL)
	{
		if ((*a) == min)
			ft_pb(a, b);
		else if ((*a)->next == min)
			ft_sa(a);
		else if ((*a)->next->next == min)
			ft_ra(a);
		else if ((*a)->next->next->next == min)
			ft_rra(a);
		else if ((*a)->next->next->next->next == min)
			ft_rra(a);
	}
	sort4(a, b);
	ft_pa(a, b);
}

void	input_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsizepush(a);
	if (check_sort(a) == 0)
		return ;
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, b);
	else if (size == 5)
		sort5(a, b);
	else
		radix(a, b);
}
