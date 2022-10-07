/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:47:28 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/23 17:36:48 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_mylist *lst)
{
	if (lst)
	{
		free(lst);
	}
}

void	ft_lstclear(t_mylist **lst)
{
	t_mylist	*current;

	while ((*lst))
	{
		current = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = current;
	}
}

void	ft_myfree_c(t_move *papillon)
{
	if (papillon->arr)
		free(papillon->arr);
	if (papillon->a)
		ft_lstclear(&(papillon->a));
	if (papillon->b)
		ft_lstclear(&(papillon->b));
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}
