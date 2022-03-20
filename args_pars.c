/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:38:53 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 17:07:59 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_move(t_move *papillon, int argc)
{
	papillon->a = malloc(sizeof(t_mylist));
	papillon->b = NULL;
	if (!papillon->a)
	{
		free (papillon->a);
		exit (EXIT_FAILURE);
	}
	papillon->arr = malloc(sizeof(int) * (argc - 1));
	if (!papillon->arr)
	{
		free(papillon->arr);
		exit(EXIT_FAILURE);
	}
	papillon->a->next = NULL;
}

int	*ft_fill(int count, t_move *list, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < count)
	{	
		list->arr[i] = ft_atoi(str[j]);
		i++;
		j++;
	}
	return (list->arr);
}

int	if_has_duplicates(t_move *papillon, int n)
{
	int	i;
	int	j;

	i = 0;
	if (n <= 1)
		return (0);
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (papillon->arr[i] == papillon->arr[j])
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_sorted(t_move *papillon, int n)
{
	int	i;

	if (n <= 1)
		return (1);
	i = 0;
	while (i < n - 1)
	{
		if (papillon->arr[i] > papillon->arr[i + 1])
			return (0);
		i++;
	}
	exit(EXIT_SUCCESS);
}

void	ft_fillist(t_move *papillon, int n)
{
	int			i;
	t_mylist	*node;

	node = ft_add_node(papillon->arr[0]);
	papillon->a = node;
	i = 1;
	while (i < n)
	{
		node->next = ft_add_node(papillon->arr[i]);
		if (!node->next)
			ft_error();
		node = node->next;
		i++;
	}
}
