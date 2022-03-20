/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:28:21 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 20:15:07 by nbenjami         ###   ########.fr       */
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

void	ft_fix(t_mylist **stack_a, int min)
{
	while ((*stack_a)->value != min)
		ft_ra(stack_a, 1);
}

void	ft_print_rr(int *arr)
{
	int	i;

	i = 0;
	while ((i < arr[RA] && i < arr[RB]) && write(1, "rr\n", 3))
		i++;
	if (arr[RA] > arr[RB])
		while (i < arr[RA] && write(1, "ra\n", 3))
			i++;
	else
		while (i < arr[RB] && write(1, "rb\n", 3))
			i++;
	i = 0;
	while ((i < arr[RRA] && i < arr[RRB]) && write(1, "rrr\n", 4))
		i++;
	if (arr[RRA] > arr[RRB])
		while (i < arr[RRA] && write(1, "rra\n", 4))
			i++;
	else
		while (i < arr[RRB] && write(1, "rrb\n", 4))
			i++;
}
