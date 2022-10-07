/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:04:36 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/30 17:45:41 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_over_five(t_move	*stacks)
{
	int	size;
	int	size_a;
	int	arr[4];

	ft_move_to_b(stacks);
	ft_3sort(stacks);
	size = ft_lstsize(stacks->b);
	size_a = 3;
	while (stacks->b)
	{
		arr[RA] = 0;
		arr[RB] = 0;
		arr[RRA] = 0;
		arr[RRB] = 0;
		ft_find_score(stacks, size, size_a);
		ft_rotate_b(&stacks->b, arr);
		ft_move_to_a(stacks, size_a, arr);
		size--;
		size_a++;
	}
	ft_fix(&stacks->a, stacks->min, size_a);
}

void	ft_rotate_b(t_mylist **stack_b, int *arr)
{
	t_mylist	*score_min;
	t_mylist	*b;

	b = *stack_b;
	score_min = b;
	while (b)
	{
		if (score_min->score > b->score)
			score_min = b;
		b = b->next;
	}
	while (score_min->score != (*stack_b)->score)
	{
		if (score_min->b_move == 0)
			arr[RB] += ft_rb(stack_b, 1);
		else
			arr[RRB] += ft_rrb(stack_b, 1);
	}
}

void	ft_move_to_a(t_move *stack, int size_a, int *arr)
{
	t_mylist	*copy;
	t_mylist	*tmp;
	int			acc;

	tmp = ft_lstlast(stack->a);
	acc = 0;
	copy = stack->a;
	if (stack->b->value > tmp->value && stack->b->value < copy->value)
	{
		ft_pa(&stack->a, &stack->b);
		return ;
	}
	while (copy->next)
	{
		acc++;
		if (copy->value < stack->b->value
			&& stack->b->value < copy->next->value)
			break ;
		copy = copy->next;
	}
	ft_rotate(&stack->a, acc, size_a, arr);
	ft_pa(&stack->a, &stack->b);
}

void	ft_rotate(t_mylist **stack, int acc, int size, int *arr)
{
	if (size / 2 >= acc)
		while (acc--)
			arr[RA] += ft_ra(stack, 1);
	else
	{
		acc = size - acc;
		while (acc--)
			arr[RRA] += ft_rra(stack, 1);
	}
}

void	ft_move_to_b(t_move *stacks)
{
	while (ft_lstsize(stacks->a) != 3)
	{
		if (stacks->a->value == stacks->mid || stacks->a->value == stacks->max
			|| stacks->a->value == stacks->min)
			ft_ra(&stacks->a, 1);
		else
		{
			ft_pb(&stacks->a, &stacks->b);
			if (stacks->b->value > stacks->mid)
				ft_rb(&stacks->b, 1);
		}
	}
}
