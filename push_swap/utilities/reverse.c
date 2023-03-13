/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:31:12 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/08 01:27:10 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "../header/push_swap.h"

// REVERSE ROTATE
// [rra] shift down all elements of stack a by 1.
void reverse_rotate_a(t_data *stack, int check)
{
	int last;
	int *new_stack;

	if (stack->size_a < 2)
	{
		return;
	}
	last = stack->stack_a[stack->size_a - 1];
	new_stack = malloc(sizeof(int) * stack->size_a);
	ft_memcpy(new_stack + 1, stack->stack_a, sizeof(int) * (stack->size_a - 1));
	new_stack[0] = last;
	ft_memcpy(stack->stack_a, new_stack, sizeof(int) * stack->size_a);
	free(new_stack);
	if (check == 1)
	{
		ft_printf("rra\n");
	}
}

// [rrb] shift down all elements of stack b by 1.
void reverse_rotate_b(t_data *stack, int check)
{
	int last;
	int *new_stack;

	if (stack->size_b < 2)
	{
		return;
	}
	last = stack->stack_b[stack->size_b - 1];
	new_stack = malloc(sizeof(int) * stack->size_b);
	ft_memcpy(new_stack + 1, stack->stack_b, sizeof(int) * (stack->size_b - 1));
	new_stack[0] = last;
	ft_memcpy(stack->stack_b, new_stack, sizeof(int) * stack->size_b);
	free(new_stack);
	if (check == 1)
	{
		ft_printf("rrb\n");
	}
}

// [rrr] rra and rrb at the same time.
void rrr(t_data *stack, int check)
{
	reverse_rotate_a(stack, 0);
	reverse_rotate_b(stack, 0);
	check = 1;
	if (check == 1)
	{
		ft_printf("rrr\n");
	}
}
