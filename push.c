/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:18:15 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/29 10:56:01 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*firstp;
	t_stack	*tmp;

	tmp = *b;
	if (a == NULL)
		return ;
	firstp = *a;
	*a = firstp->next;
	*b = firstp;
	if (tmp != NULL)
		firstp->next = tmp;
	else
		firstp->next = NULL;
}

void	ft_pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
