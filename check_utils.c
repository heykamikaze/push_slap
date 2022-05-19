/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:47:28 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/19 18:15:30 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_myfree_c(t_move *papillon, char **argv)//smwhr here is the malloc error
{
	t_mylist	*tmp;
	int			i;

	tmp = papillon->a;
	while (papillon->a)
	{
		tmp = tmp->next;
		free (papillon->a);
		papillon->a = tmp;
	}
	i = 0;
	if (argv)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}
