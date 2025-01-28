/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxminindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:16:40 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/29 10:56:23 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_index(t_stack **a)
{
	t_stack	*maxin;
	t_stack	*stack;

	if (!a)
		return (NULL);
	maxin = *a;
	stack = maxin->next;
	while (stack != NULL)
	{
		if (maxin->index < stack->index)
		{
			maxin = stack;
			stack = stack->next;
		}
		else
			stack = stack->next;
	}
	return (maxin);
}

t_stack	*min_index(t_stack **a)
{
	t_stack	*minin;
	t_stack	*stack;

	if (!a)
		return (NULL);
	minin = *a;
	stack = minin->next;
	while (stack != NULL)
	{
		if (minin->index > stack->index)
		{
			minin = stack;
			stack = stack->next;
		}
		else
			stack = stack->next;
	}
	return (minin);
}
