/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:10:31 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/19 17:48:57 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_commands(char *cmd, t_move *papillon)
{
	if (ft_strcmp(cmd, "pa\n"))
		ft_pa_checker(&papillon->a, &papillon->b);
	else if (ft_strcmp(cmd, "pb\n"))
		ft_pb_checker(&papillon->a, &papillon->b);
	else if (ft_strcmp(cmd, "sa\n"))
		ft_sa(&papillon->a, 0);
	else if (ft_strcmp(cmd, "sb\n"))
		ft_sb(&papillon->b, 0);
	else if (ft_strcmp(cmd, "ra\n"))
		ft_ra(&(papillon->a), 0);
	else if (ft_strcmp(cmd, "rb\n"))
		ft_rb(&(papillon->b), 0);
	else if (ft_strcmp(cmd, "rra\n"))
		ft_rra(&(papillon->a), 0);
	else if (ft_strcmp(cmd, "rrb\n"))
		ft_rrb(&(papillon->b), 0);
	else if (ft_strcmp(cmd, "rrr\n"))
		ft_rrr_checker(papillon);
	else if (ft_strcmp(cmd, "rr\n"))
		ft_rr_checker(papillon);
	else if (ft_strcmp(cmd, "ss\n"))
		ft_ss_checker(papillon);
	else
		ft_error();
}

void	ft_check(t_move *papillon)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd && cmd[0] != '\n')
	{
		ft_commands(cmd, papillon);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (cmd)
		free(cmd);
}

int	checklsts_helper(t_mylist *tmp, t_mylist *head, int min)
{
	while (tmp->value != min)
	{
		if (head->value > tmp->value)
			return (0);
		head = head->next;
		tmp = tmp->next;
	}
	return (1);
}

int	checklst_sort(t_mylist *head, int min)
{
	t_mylist	*next_head;
	t_mylist	*dup;

	dup = head;
	while (head && head->value != min)
		head = head->next;
	next_head = head->next;
	while (next_head)
	{
		if (head->value > next_head->value)
			return (0);
		head = head->next;
		next_head = head->next;
	}
	if (head->value > dup->value && dup->value != min)
		return (0);
	else if (head->value > dup->value && dup->value == min)
		return (1);
	head = dup;
	dup = dup->next;
	return (checklsts_helper(dup, head, min));
}

int	main(int argc, char **argv)
{
	t_move	papillon;
	int		size;

	init_move(&papillon, argc);
	ft_fill(argc, &papillon, argv);
	if_has_duplicates(&papillon, argc - 1);
	ft_is_sorted(&papillon, argc - 1);
	ft_fillist(&papillon, argc - 1);
	ft_check(&papillon);
	size = ft_lstsize(papillon.a);
	if (size == 1 || (checklst_sort(papillon.a, papillon.a->value) \
	&& size == ft_lstsize(papillon.a)))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
