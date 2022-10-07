/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:48:15 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/24 17:51:33 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa_checker(t_mylist **a_head, t_mylist **b_head)
{
	t_mylist	*b_next;

	if (*b_head)
	{
		b_next = (*b_head)->next;
		ft_lstadd_front(a_head, *b_head);
		*b_head = b_next;
	}
	return (1);
}

int	ft_pb_checker(t_mylist **stack_a, t_mylist **stack_b)
{
	t_mylist	*tmp;
	t_mylist	*a;
	t_mylist	*b;

	a = *stack_a;
	b = *stack_b;
	if (!a)
		return (1);
	tmp = a;
	a = a->next;
	*stack_a = a;
	if (!b)
	{
		b = tmp;
		b->next = NULL;
		*stack_b = b;
	}
	else
	{
		tmp->next = b;
		*stack_b = tmp;
	}
	return (1);
}

int	ft_rrr_checker(t_move *stack)
{
	ft_rra(&stack->a, 0);
	ft_rrb(&stack->b, 0);
	return (1);
}

int	ft_ss_checker(t_move *stack)
{
	ft_sa(&stack->a, 0);
	ft_sb(&stack->b, 0);
	return (1);
}

int	ft_rr_checker(t_move *stack)
{
	ft_ra(&stack->a, 0);
	ft_rb(&stack->b, 0);
	return (1);
}
