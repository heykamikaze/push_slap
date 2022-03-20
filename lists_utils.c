/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:10:38 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 19:19:28 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mylist	*ft_lstlast(t_mylist *lst)
{
	if (!(lst))
		return (lst);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_mylist **lst, t_mylist *new)
{
	t_mylist	*last;

	if (!(lst))
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	ft_lstadd_front(t_mylist **lst, t_mylist *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_mylist *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	ft_rrr(t_move *stack)
{
	ft_rra(&stack->a, 0);
	ft_rrb(&stack->b, 0);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}
