/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:31:12 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/08 01:27:11 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "../header/push_swap.h"

// ROTATE
// [ra] shift up all elements of stack a by 1.
void rotate_a(t_data *stack, int check)
{
	int first;
	int *new_stack;

	if (stack->size_a < 2)
	{
		return;
	}
	first = stack->stack_a[0];
	new_stack = malloc(sizeof(int) * stack->size_a);
	ft_memcpy(new_stack, stack->stack_a + 1, sizeof(int) * (stack->size_a - 1));
	new_stack[stack->size_a - 1] = first;
	ft_memcpy(stack->stack_a, new_stack, sizeof(int) * stack->size_a);
	free(new_stack);
	if (check == 1)
	{
		ft_printf("ra\n");
	}
}

// [rb] shift up all elements of stack b by 1.
void rotate_b(t_data *stack, int check)
{
	int first;
	int *new_stack;

	if (stack->size_b < 2)
	{
		return;
	}
	first = stack->stack_b[0];
	new_stack = malloc(sizeof(int) * stack->size_b);
	ft_memcpy(new_stack, stack->stack_b + 1, sizeof(int) * (stack->size_b - 1));
	new_stack[stack->size_b - 1] = first;
	ft_memcpy(stack->stack_b, new_stack, sizeof(int) * stack->size_b);
	free(new_stack);
	if (check == 1)
	{
		ft_printf("rb\n");
	}
}

// [rr] ra and rb at the same time
void rr(t_data *stack, int check)
{
	rotate_a(stack, 0);
	rotate_b(stack, 0);
	check = 1;
	if (check == 1)
	{
		ft_printf("rr\n");
	}
}
