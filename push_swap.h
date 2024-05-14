/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:24:26 by jeandrad          #+#    #+#             */
/*   Updated: 2024/03/04 17:24:26 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

void	ft_lst_split(t_list **stack_a, t_list **stack_b, int size);
void	ft_write_lst(t_list **stack_a, int argc, char **argv, int i);
void	ft_lstcheck(t_list *stack_a, int check);
void	ft_lst_order(t_list **stack_a);
void	ft_lst_inverted(t_list **stack_a);
void	ft_lst_delete(t_list **stack);
void	ft_display_error(void);
void	*ft_free_arg(char **arg);

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_b, t_list **stack_a);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_sort_three(t_list **stack_a);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);

void	ft_check_argv(int argc, char **argv, t_list **stack_a);
int		ft_check_format(int argc, char **argv);
int		ft_str_format_check(const char *str);
int		ft_atoi_mod(const char *str);

void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max);
void	ft_move_to_a(t_list **stack_a, t_list **stack_b);
int		ft_best_nbr_b(t_list **stack_b, int size_b,
			t_list **stack_a, int size_a);
int		ft_best_nbr_a(t_list *stack_a, int size, int *arr, int max);
int		ft_best_comb(int *arr_a, int *arr_b, int size);
int		ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size);
int		ft_move_a(int a, int b, t_list **stack_a, t_list **stack_b);
void	ft_search_min(t_list **stack_a, int size);

int		*ft_copy_cont(t_list *stack_a, int size);
int		*ft_intcpy(int	*arr, int size);

int		ft_the_needed(int min, int max, int size);
int		ft_the_needed_a(t_list *stack_a, int cont, int size);
int		ft_the_needed_b(int max, int size);
int		ft_max_nbr(int a, int b);
int		ft_min_nbr(int a, int b);
int		ft_max_or_min(t_list *stack_a, int cont, int size);
int		return_max_or_min(int cont, int *max_n_min, int size);

t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
bool	ft_stack_b_empty(t_list *stack_b);

int		*ft_define_lis(int *dst, int size, int *max);
int		*ft_long_lis(int *dst, int *arr, int size, int *ret);
int		*ft_lis_util(int *dst, int *arr, int max, int size);
int		*ft_lis_util_helper(int max);

void	ft_exec_sort(t_list **stack_a, t_list **stack_b, char *str);
void	ft_rrr_or_death(t_list **stack_a, t_list **stack_b, char *str);
void	ft_check_write_lst(t_list **stack_a, int argc, char **argv, int i);
void	ft_check_lst_inverted(t_list **stack_a);
void	ft_check_sort(t_list *stack_a);
void	ft_check_argv_c(int argc, char **argv, t_list **stack_a);
void	ft_sa_check(t_list **stack_a);
void	ft_sb_check(t_list **stack_b);
void	ft_ss_check(t_list **stack_a, t_list **stack_b);
void	ft_pa_check(t_list **stack_b, t_list **stack_a);
void	ft_pb_check(t_list **stack_a, t_list **stack_b);
void	ft_ra_check(t_list **stack_a);
void	ft_rb_check(t_list **stack_b);
void	ft_rr_check(t_list **stack_a, t_list **stack_b);
void	ft_rra_check(t_list **stack_a);
void	ft_rrb_check(t_list **stack_b);
void	ft_rrr_check(t_list **stack_a, t_list **stack_b);
int		ft_strcmp(char *s1, char *s2);

#endif
