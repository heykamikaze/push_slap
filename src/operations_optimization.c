/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_optimization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:20:45 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/20 21:25:42 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ss(t_move *stack)
{
	ft_sa(&stack->a, 0);
	ft_sb(&stack->b, 0);
	ft_putstr_fd("ss\n", 1);
	return (1);
}

int	ft_rr(t_move *stack)
{
	ft_ra(&stack->a, 0);
	ft_rb(&stack->b, 0);
	ft_putstr_fd("rr\n", 1);
	return (1);
}

int	ft_rra(t_mylist **stack_a, int n)
{
	t_mylist	*tmp;
	t_mylist	*tmp1;
	t_mylist	*a;

	a = *stack_a;
	if (!a || a->next == NULL)
		return (1);
	tmp = a;
	while (a->next)
	{
		tmp1 = a;
		a = a->next;
	}
	a->next = tmp;
	tmp1->next = NULL;
	*stack_a = a;
	if (n == 1)
		ft_putstr_fd("rra\n", 1);
	return (1);
}

int	ft_rrb(t_mylist **stack_b, int n)
{
	t_mylist	*tmp;
	t_mylist	*tmp1;
	t_mylist	*b;

	b = *stack_b;
	if (!b || b->next == NULL)
		return (1);
	tmp = b;
	while (b->next)
	{
		tmp1 = b;
		b = b->next;
	}
	b->next = tmp;
	tmp1->next = NULL;
	*stack_b = b;
	if (n == 1)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	ft_sb(t_mylist **stack, int n)
{
	t_mylist	*head;
	int			tmp;

	head = *stack;
	if (!head || !head->next)
		return (1);
	tmp = head->value;
	head->value = head->next->value;
	head->next->value = tmp;
	if (n == 1)
		ft_putstr_fd("sb\n", 1);
	return (1);
}
