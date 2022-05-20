/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:47:28 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/20 20:17:10 by nbenjami         ###   ########.fr       */
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

// void	ft_lstclear(t_mylist **lst, void (*del)(void*))
// {
// 	t_mylist	*src;

// 	while ((*lst))
// 	{
// 		src = *lst;
// 		del(src->content);
// 		*lst = (*lst)->next;
// 		free(src);
// 	}
// }

// void	ft_lstclear(t_mylist **lst, void (*del)(void*))
// {
// 	t_mylist	*src;

// 	while ((*lst))
// 	{
// 		src = *lst;
// 		del(src->content);
// 		*lst = (*lst)->next;
// 		free(src);
// 	}
// }


void	ft_myfree_c(t_move *papillon)//smwhr here is the malloc error
{
	// t_mylist	*tmp;
	// t_mylist	*tmp_b;

	// tmp_b = papillon->b;
	// tmp = papillon->a;
	// while (papillon->a)
	// {
	// 	tmp = tmp->next;
	// 	free (papillon->a);
	// 	papillon->a = tmp;
	// }
	// tmp_b = papillon->b;
	// if (papillon->b)
		// {
		// 	while (papillon->b)
		// 	{
		// 		tmp_b = tmp_b->next;
		// 		free (papillon->b);
		// 		papillon->b = tmp_b;
		// 	}
		// }
	// if (papillon->b)
	// 	free (papillon->b);
	if (papillon->arr)
		free(papillon->arr);
	// if (papillon)
	// {
		if (papillon->a)
			ft_lstclear(&(papillon->a));
		if (papillon->b)
			ft_lstclear(&(papillon->b));
		// free(papillon);
	}
	// free (tmp);
	// i = 1;
	// if (argv)
	// {
		// while (i != argc - 1)
		// {
		// 	free(argv[i]);
		// 	i++;
		// }
		// free(argv);
	// }


int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}
