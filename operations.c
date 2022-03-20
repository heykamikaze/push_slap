/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:36:30 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 20:02:01 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_mylist **stack, int n)
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
		ft_putstr_fd("sa\n", 1);
	return (1);
}

int	ft_pb(t_mylist **stack_a, t_mylist **stack_b)
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
	ft_putstr_fd("pb\n", 1);
	return (1);
}

int	ft_pa(t_mylist **a_head, t_mylist **b_head)
{
	t_mylist	*b_next;

	write(1, "pa\n", 3);
	if (*b_head)
	{
		b_next = (*b_head)->next;
		ft_lstadd_front(a_head, *b_head);
		*b_head = b_next;
	}
	return (1);
}

int	ft_ra(t_mylist **a_head, int printflag)
{
	t_mylist	*new_last;
	t_mylist	*new_first;

	if (printflag == 1)
		write(1, "ra\n", 3);
	new_last = *a_head;
	if (new_last)
	{
		new_first = (*a_head)->next;
		if (new_first)
		{
			ft_lstadd_back(a_head, new_last);
			*a_head = new_first;
			new_last->next = NULL;
		}
	}
	return (1);
}

int	ft_rb(t_mylist **a_head, int printflag)
{
	t_mylist	*new_last;
	t_mylist	*new_first;

	if (printflag == 1)
		write(1, "rb\n", 3);
	new_last = *a_head;
	if (new_last)
	{
		new_first = (*a_head)->next;
		if (new_first)
		{
			ft_lstadd_back(a_head, new_last);
			*a_head = new_first;
			new_last->next = NULL;
		}
	}
	return (1);
}
