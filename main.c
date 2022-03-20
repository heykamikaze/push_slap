/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:35:33 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 16:31:07 by nbenjami         ###   ########.fr       */
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
		init_move(&papillon, argc);
		ft_fill(argc, &papillon, argv);
		if_has_duplicates(&papillon, argc - 1);
		ft_is_sorted(&papillon, argc - 1);
		ft_fillist(&papillon, argc - 1);
		ft_arr_sort(&papillon, argc);
		if (argc > 6)
			sort_over_five(&papillon);
		else
			ft_minisort(&papillon, argc);
	}
	return (0);
}
