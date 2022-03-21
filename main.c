/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:35:33 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/21 16:52:54 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_move	papillon;
	int		i;

	i = 0;
	if (argc != 1)
	{
		ft_putstr_fd("1111\n", 2);
		init_move(&papillon, argc);
		ft_putstr_fd("22222\n", 2);
		ft_fill(argc, &papillon, argv);
		ft_putstr_fd("3333333\n", 2);
		if_has_duplicates(&papillon, argc - 1);
		ft_is_sorted(&papillon, argc - 1);
		ft_fillist(&papillon, argc - 1);
		ft_arr_sort(&papillon, argc);
		if (argc > 6)
			sort_over_five(&papillon);
		else
			ft_minisort(&papillon, argc);
		ft_myfree(&papillon);
	}
	return (0);
}

void	ft_myfree(t_move *papillon)
{
	t_mylist	*tmp;

	tmp = papillon->a;
	while (papillon->a)
	{
		tmp = tmp->next;
		free (papillon->a);
		papillon->a = tmp;
	}
}
