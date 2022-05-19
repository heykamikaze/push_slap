/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:28:21 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/23 16:40:33 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_score_a(t_mylist *a, int value, int size_a)
{
	int			acc;
	t_mylist	*tail;

	tail = ft_lstlast(a);
	acc = 0;
	if (value < a->value && value > tail->value)
		return (acc);
	while (a->next)
	{
		acc++;
		if (value < a->next->value && value > a->value)
			break ;
		a = a->next;
	}
	if (size_a / 2 >= acc)
		return (acc);
	else
	{
		a->a_move = 1;
		return (size_a - acc);
	}
}

void	ft_find_score(t_move *stack, int size, int size_a)
{
	int			acc;
	t_mylist	*a;
	t_mylist	*b;

	acc = 0;
	b = stack->b;
	while (b)
	{
		a = stack->a;
		if (acc >= size / 2 + 1)
		{
			b->score = size - acc + ft_score_a(a, b->value, size_a);
			b->b_move = 1;
		}
		else
		{
			b->score = acc + ft_score_a(a, b->value, size_a);
			b->b_move = 0;
		}
		acc++;
		b = b->next;
	}
}

void	ft_fix(t_mylist **stack_a, int min, int size_a)
{
	t_mylist	*tmp;
	int			i;

	tmp = *stack_a;
	i = 0;
	while (tmp->value != min)
	{
		tmp = tmp->next;
		i++;
	}
	if (size_a / 2 >= i)
		while (i--)
			ft_ra(stack_a, 1);
	else
	{
		i = size_a - i;
		while (i--)
			ft_rra(stack_a, 1);
	}
}
