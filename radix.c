/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:57:17 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/29 10:56:53 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_bit(t_stack **a)
{
	t_stack	*heap;
	int		max;
	int		max_bit;

	max_bit = 0;
	heap = *a;
	max = heap->index;
	while (heap != NULL)
	{
		if (heap->index > max)
			max = heap->index;
		heap = heap->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix(t_stack **a, t_stack **b)
{
	int	max_bit;
	int	t;
	int	i;
	int	size;

	max_bit = ft_max_bit(a);
	size = ft_lstsizepush(a);
	i = 0;
	while (i < max_bit)
	{
		t = 0;
		while (t++ < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				ft_pb(a, b);
			else
				ft_ra(a);
		}
		while (ft_lstsizepush(b) != 0)
			ft_pa(a, b);
		i++;
	}
}
