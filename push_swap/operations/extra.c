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
This is a function that calculates the distance (number of elements) between the top of a stack and a specified index in the stack. It takes two parameters, a pointer to a pointer to the first element of the stack (stack), and an integer representing the index of the element to calculate the distance to (index).
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
If the distance is less than or equal to half the size of the stack, the function uses the "ra" operation (presumably defined elsewhere in the code) to move the top element down the stack. It does this by repeatedly calling "ra" distance times, effectively moving the top element down the stack by distance positions.
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
