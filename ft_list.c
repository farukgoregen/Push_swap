/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:26:17 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/01 13:04:39 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlaststac(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_backst(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlaststac(*lst)->next = new;
}

t_stack	*ft_lstnews(int content)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstlastpush(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsizepush(t_stack **lst)
{
	t_stack	*stl;
	size_t	i;

	stl = *lst;
	i = 1;
	if (!stl)
		return (0);
	while (stl->next != NULL)
	{
		stl = stl->next;
		i++;
	}
	return (i);
}
