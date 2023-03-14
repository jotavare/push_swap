/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:31:12 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/14 02:06:53 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

	/*
	Performs a reverse order of the linked list stack byswapping
	its first and last elements. It returns -1 if the stack has less
	than 2 elements.
	*/

static int	reverse(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

	/*
	Performs a reverse rotation of a linked list stack (A) by
	moving its last element to the beginning. Prints "rra".
	*/

int	rra(t_list **stack_a)
{
	if (reverse(stack_a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

	/*
	Performs a reverse rotation of a linked list stack (B) by
	moving its last element to the beginning. Prints "rrb".
	*/

int	rrb(t_list **stack_b)
{
	if (reverse(stack_b) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

	/*
	Performs a simultaneous reverse rotation of both linked list stacks
	(A and B) by moving their last elements to the beginning. Prints "rrr".
	*/

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}
