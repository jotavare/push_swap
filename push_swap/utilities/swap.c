/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:31:12 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/13 20:09:58 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "../header/push_swap.h"

// SWAP
// swap the first 2 elements at the top of stack a
void swap_a(t_data *stack, int check)
{
	int tmp;

	if (stack->size_a < 2)
	{
		return;
	}
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	if (check == 1)
	{
		ft_printf("sa\n");
	}
}

// swap the first 2 elements at the top of stack b.
void swap_b(t_data *stack, int check)
{
	int tmp;

	if (stack->size_b < 2)
	{
		return;
	}
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	if (check == 1)
	{
		ft_printf("sb\n");
	}
}

// sa and sb at the same time.
void ss(t_data *stack, int check)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	check = 1;
	if (check == 1)
	{
		ft_printf("ss\n");
	}
}
