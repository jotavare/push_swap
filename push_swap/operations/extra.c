/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:09:09 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/14 02:06:51 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

	/*
	This function calculates the distance between a given
	index and the head of a linked list stack.
	*/

int	get_distance(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

	/*
	This function moves the top element of a linked list stack a certain
	distance away from the head of the stack using the "ra" and "rra" functions.
	*/

void	move_top(t_list **stack, int distance)
{
	t_list	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = ft_lstsize(head) - distance;
	if (distance <= (ft_lstsize(head) / 2))
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack);
	}
}
