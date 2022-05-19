/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:10:31 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/19 17:33:32 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}

void	ft_commands(char *cmd, t_move *papillon, int flag_correct)
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
	{
		flag_correct = 0;
		ft_error();
	}
}

int	ft_check(t_move *papillon)
{
	char	*cmd;
	int		flag_correct;

	flag_correct = 1;
	cmd = get_next_line(0);
	while (cmd && cmd[0] != '\n')
	{
		ft_commands(cmd, papillon, flag_correct);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (cmd)
		free(cmd);
	// exit(1);
	return (flag_correct);
}

int	checklsts_helper(t_mylist *dup, t_mylist *head, int min)
{
	while (dup->value != min)
	{
		if (head->value > dup->value)
			return (0);
		head = head->next;
		dup = dup->next;
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
// int	main(int argc, char **argv)
// {
// 	t_move	papillon;
// 	int		res;
// 	int		size;
// 	int		i;

// 	// papillon = NULL;
// 	// papillon = (t_move){};
// 	i = -1;
// 	res = 0;
	
// 	init_move(&papillon, argc);
// 	ft_fill(argc, &papillon, argv);
// 	if_has_duplicates(&papillon, argc - 1);
// 	ft_is_sorted(&papillon, argc - 1);
// 	ft_fillist(&papillon, argc - 1);
// 	ft_check(&papillon);
// 		// free(&papillon);
// 	size = ft_lstsize(papillon.a - 1);
// 	printf("%d", size);
// 	while (++i < ft_lstsize(papillon.a - 1))
// 	{
// 		exit(1);
// 		if (&papillon.a->value > &papillon.a->next->value)
// 		{
// 			res = 1;
// 			ft_myfree_c(&papillon);
// 		}
// 		// printf("%d", papillon.a->value);
// 		while (papillon.a->next)
// 			papillon.a = papillon.a->next;//segfault here
// 	}
// 	if (res == 0)
// 		ft_putstr_fd("OK\n", 1);
// 	else
// 		ft_putstr_fd("KO\n", 1);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_move	papillon;
	int		size;

	// papillon = NULL;
	// papillon = (t_move){};	
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

void	ft_myfree_c(t_move *papillon)
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