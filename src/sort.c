/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:47:10 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 20:09:05 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minisort(t_move *papillon, int argc)
{
	if (argc - 1 == 2)
		ft_sa(&papillon->a, 1);
	if (argc - 1 == 3)
		ft_3sort(papillon);
	if (argc - 1 == 4)
		ft_sort4(papillon->a, papillon);
	if (argc - 1 == 5)
		ft_sort5(papillon->a, papillon);
	return (1);
}

int	ft_3sort(t_move *pa)
{
	if (pa->a->value > pa->a->next->value
		&& pa->a->value > pa->a->next->next->value)
	{
		if (pa->a->next->value > pa->a->next->next->value)
		{
			ft_ra(&pa->a, 1);
			ft_sa(&pa->a, 1);
		}
		else
			ft_ra(&pa->a, 1);
	}
	else if (pa->a->next->value > pa->a->value
		&& pa->a->next->value > pa->a->next->next->value)
	{
		ft_rra(&pa->a, 1);
		if (pa->a->value > pa->a->next->value)
			ft_sa(&pa->a, 1);
	}
	else if (pa->a->next->next->value > pa->a->next->value
		&& pa->a->next->next->value > pa->a->value
		&& pa->a->value > pa->a->next->value)
		ft_sa(&pa->a, 1);
	return (1);
}

int	ft_sort4(t_mylist *stack_a, t_move *papillon)
{
	if (stack_a->next->value > stack_a->value
		&& stack_a->next->value > stack_a->next->next->value
		&& stack_a->next->value > stack_a->next->next->next->value)
		ft_ra(&papillon->a, 1);
	else if (stack_a->next->next->value > stack_a->next->value
		&& stack_a->next->next->value > stack_a->value
		&& stack_a->next->next->value > stack_a->next->next->next->value)
	{
		ft_ra(&papillon->a, 1);
		ft_ra(&papillon->a, 1);
	}
	else if (stack_a->next->next->next->value > stack_a->next->value
		&& stack_a->next->next->next->value > stack_a->next->next->value
		&& stack_a->next->next->next->value > stack_a->value)
		ft_rra(&papillon->a, 1);
	ft_pb(&papillon->a, &papillon->b);
	ft_3sort(papillon);
	ft_pa(&papillon->a, &papillon->b);
	ft_ra(&papillon->a, 1);
	return (1);
}

int	ft_sort5(t_mylist *stack_a, t_move *papillon)
{
	if (stack_a->next->value > stack_a->value && stack_a->next->value
		> stack_a->next->next->value && stack_a->next->value
		> stack_a->next->next->next->value
		&& stack_a->next->value > stack_a->next->next->next->next->value)
		ft_ra(&papillon->a, 1);
	else if (stack_a->next->next->value > stack_a->value
		&& stack_a->next->next->value > stack_a->next->value
		&& stack_a->next->next->value > stack_a->next->next->next->value
		&& stack_a->next->next->value > stack_a->next->next->next->next->value)
		sort5_additionals(papillon, 1);
	else if (stack_a->next->next->next->value > stack_a->value
		&& stack_a->next->next->next->value > stack_a->next->value
		&& stack_a->next->next->next->value > stack_a->next->next->value
		&& stack_a->next->next->next->value
		> stack_a->next->next->next->next->value)
		sort5_additionals(papillon, 2);
	else if (stack_a->next->next->next->next->value > stack_a->value
		&& stack_a->next->next->next->next->value > stack_a->next->value
		&& stack_a->next->next->next->next->value > stack_a->next->next->value
		&& stack_a->next->next->next->next->value
		> stack_a->next->next->next->value)
		ft_rra(&papillon->a, 1);
	sort5_additionals(papillon, 3);
	return (1);
}

void	sort5_additionals(t_move *papillon, int code)
{
	if (code == 1)
	{
		ft_ra(&papillon->a, 1);
		ft_ra(&papillon->a, 1);
	}
	if (code == 2)
	{
		ft_rra(&papillon->a, 1);
		ft_rra(&papillon->a, 1);
	}
	if (code == 3)
	{
		ft_pb(&papillon->a, &papillon->b);
		ft_sort4(papillon->a, papillon);
		ft_pa(&papillon->a, &papillon->b);
		ft_ra(&papillon->a, 1);
	}
}
