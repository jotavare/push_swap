/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:06:28 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/14 02:06:50 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBRARY
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>	// BOOL DATA TYPE
# include <limits.h>	// INT_MAX AND INT_MIN
# include <math.h>		// POW

/* utility */
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;


t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
size_t	ft_strlen(const char *str);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	index_stack(t_list **stack);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ps_error(char *msg);
void	ps_free(char **str);
void	free_stack(t_list **stack);
void	check_args(int argc, char **argv);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
int		ft_lstsize(t_list *head);
int		ft_isdigit(int c);
int		is_sorted(t_list **stack);

/* operation */
void	move_top(t_list **stack, int distance);
int		get_distance(t_list **stack, int index);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

/* sorting */
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
int		get_min(t_list **stack, int val);

/* main.c */

#endif
