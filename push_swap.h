/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:38:38 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/19 17:29:31 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RA 0
# define RB 1
# define RRA 2
# define RRB 3

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_mylist
{
	struct s_mylist	*next;
	int				value;
	int				score;
	int				b_move;
	int				a_move;
}	t_mylist;

typedef struct s_move
{
	t_mylist	*a;
	t_mylist	*b;
	int			*arr;
	int			mid;
	int			max;
	int			min;
}	t_move;

int			*ft_fill(int count, t_move *list, char **str);
t_mylist	*ft_add_elem(int value);
int			if_has_duplicates(t_move *papillon, int n);
int			ft_is_sorted(t_move *papillon, int n);
void		init_move(t_move *papillon, int argc);
void		ft_fillist(t_move *papillon, int n);
t_mylist	*ft_add_node(int value);
int			ft_sa(t_mylist **stack, int n);
int			ft_sb(t_mylist **stack, int n);
int			ft_ss(t_move *stack);
int			ft_pb(t_mylist **stack_a, t_mylist **stack_b);
int			ft_pa(t_mylist **stack_a, t_mylist **stack_b);
int			ft_ra(t_mylist **stack_a, int n);
int			ft_rb(t_mylist **stack_b, int n);
int			ft_rr(t_move *stack);
int			ft_rra(t_mylist **stack_a, int n);
int			ft_rrb(t_mylist **stack_b, int n);
int			ft_rrr(t_move *stack);
void		ft_lstadd_back(t_mylist **lst, t_mylist *new);
t_mylist	*ft_lstlast(t_mylist *lst);
void		ft_lstadd_front(t_mylist **lst, t_mylist *new);
int			ft_lstsize(t_mylist *stack);
int			ft_minisort(t_move *papillon, int argc);
int			ft_3sort(t_move *pa);
int			ft_sort4(t_mylist *stack_a, t_move *papillon);
int			ft_sort5(t_mylist *stack_a, t_move *papillon);
void		sort5_additionals(t_move *papillon, int code);
void		ft_arr_sort(t_move *papillon, int argc);
void		sort_over_five(t_move *stacks);
void		ft_move_to_b(t_move *stacks);
void		ft_move_to_a(t_move *stack, int size_a, int *arr); //, int *arr add
void		ft_rotate(t_mylist **stack, int acc, int size, int *arr);
void		ft_find_score(t_move *stack, int size, int size_a);
void		ft_rotate_b(t_mylist **stack_b, int *arr);
int			ft_score_a(t_mylist *a, int value, int size_a);
void		ft_fix(t_mylist **stack_a, int min, int size_a);
void		ft_myfree(t_move *papillon);
int	ft_strcmp(char *s1, char *s2);
void	ft_commands(char *cmd, t_move *papillon, int flag_correct);
void	ft_myfree_c(t_move *papillon);
int	ft_pa_checker(t_mylist **a_head, t_mylist **b_head);
int	ft_pb_checker(t_mylist **stack_a, t_mylist **stack_b);
int	ft_rrr_checker(t_move *stack);
int	ft_ss_checker(t_move *stack);
int	ft_rr_checker(t_move *stack);
int	checklst_sort(t_mylist *head, int min);
int	checklsts_helper(t_mylist *dup, t_mylist *head, int min);

#endif