/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:12 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/14 02:07:24 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

	/*
	The next 3 cases bellow are specific cases only.
	*/

static void	sort_132(t_list **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

static void	sort_231(t_list **stack_a, t_list *head, int min)
{
	if (head->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

static void	sort_312(t_list **stack_a, t_list *head, int min)
{
	if (head->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

	/*
	Sorts a stack of three numbers by selecting the appropriate sorting
	method based on their indices. Uses get_min, is_sorted, and
	sort_132, sort_231, and sort_312 to sort the stack.
	Its done this way so it can be used in the bigger algorithm.
	*/

void	sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a) == 1)
		return ;
	if (head->index == min && head->next->index != next_min)
		sort_132(stack_a);
	else if (head->index == next_min)
		sort_231(stack_a, head, min);
	else
		sort_312(stack_a, head, min);
}
