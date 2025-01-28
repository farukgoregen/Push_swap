/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:07:41 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/29 10:54:16 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_revers_rotate(t_stack **a)
{
	t_stack	*rotate;
	t_stack	*endrot;

	rotate = *a;
	endrot = ft_lstlastpush(rotate);
	while (rotate != NULL)
	{
		if (rotate->next->next == NULL)
		{
			rotate->next = NULL;
			break ;
		}
		rotate = rotate->next;
	}
	endrot->next = *a;
	*a = endrot;
}

static void	ft_rotate(t_stack **a)
{
	t_stack	*rotate;
	t_stack	*endrot;

	rotate = *a;
	endrot = ft_lstlastpush(rotate);
	*a = rotate->next;
	endrot->next = rotate;
	rotate->next = NULL;
}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rra(t_stack **a)
{
	ft_revers_rotate(a);
	write(1, "rra\n", 4);
}
