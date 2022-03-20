/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:45:59 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 20:10:52 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mylist	*ft_add_node(int value)
{
	t_mylist	*list;

	list = malloc(sizeof(t_mylist));
	if (!list)
	{
		free(list);
		return (NULL);
	}
	list->value = value;
	list->next = NULL;
	list->a_move = 0;
	list->b_move = 0;
	return (list);
}

void	ft_arr_sort(t_move *papillon, int argc)
{
	int			j;
	int			i;
	int			save;

	i = 0;
	while (i < argc - 1)
	{
		j = argc - 2;
		while (j > i)
		{
			if (papillon->arr[j - 1] > papillon->arr[j])
			{
				save = papillon->arr[j - 1];
				papillon->arr[j - 1] = papillon->arr[j];
				papillon->arr[j] = save;
			}
			j--;
		}
		i++;
	}
	papillon->mid = papillon->arr[(argc - 1) / 2];
	papillon->min = papillon->arr[0];
	papillon->max = papillon->arr[argc - 2];
	free(papillon->arr);
}
