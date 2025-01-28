/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:02:17 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/29 10:54:00 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zero_index(t_stack **a)
{
	t_stack	*zero;

	zero = *a;
	while (zero != NULL)
	{
		zero->index = 0;
		zero = zero->next;
	}
}

static t_stack	*get_min_index(t_stack **a)
{
	t_stack	*min;
	int		z;
	t_stack	*stack;

	stack = *a;
	min = NULL;
	z = -1;
	while (stack != NULL)
	{
		if (stack->index == 0 && (z == -1 || stack->data < min->data))
		{
			min = stack;
			z = 1;
		}
		stack = stack->next;
	}
	return (min);
}

void	ft_index(t_stack **a)
{
	int		i;
	t_stack	*a_index;

	zero_index(a);
	i = 0;
	a_index = get_min_index(a);
	while (a_index != NULL)
	{
		a_index->index = i++;
		a_index = get_min_index(a);
	}
}
