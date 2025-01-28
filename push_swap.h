/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:11:53 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/01 12:34:23 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				ft_error_av(int ac, char **av);
void				ft_free(char **str);
int					check_sort(t_stack **a);
t_stack				*ft_lstlaststac(t_stack *lst);
void				ft_lstadd_backst(t_stack **lst, t_stack *new);
t_stack				*ft_lstnews(int content);
void				ft_add_stack(t_stack **a, char **av, int ac);
void				ft_index(t_stack **a);
t_stack				*ft_lstlastpush(t_stack *lst);
void				ft_ra(t_stack **a);
void				ft_rra(t_stack **a);
void				ft_sa(t_stack **a);
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
int					ft_lstsizepush(t_stack **lst);
t_stack				*max_index(t_stack **a);
void				input_sort(t_stack **a, t_stack **b);
t_stack				*min_index(t_stack **a);
void				radix(t_stack **a, t_stack **b);
#endif