/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:38:19 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/29 10:54:28 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **a)
{
	t_stack	*first;
	t_stack	*two;

	first = *a;
	two = first->next;
	*a = two;
	first->next = two->next;
	two->next = first;
}

void	ft_sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}
