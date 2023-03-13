/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:31:12 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/07 23:40:15 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "../header/push_swap.h"

// FREE ALL
void free_all(t_data *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
}

// EXIT ERROR
void exit_error(t_data *stack)
{
	if (stack->stack_a == NULL)
	{
		free(stack->stack_a);
	}
	if (stack->stack_b == NULL)
	{
		free(stack->stack_b);
	}
	ft_printf("Error\n");
	exit(1);
}

// MAX NUMBER FROM STACK A
int max_value(t_data *stack)
{
	int i = 0;

	while (i < stack->size_a)
	{
		if (stack->stack_a[i] > stack->max)
		{
			stack->max = stack->stack_a[i];
		}
		i++;
	}

	return stack->max;
}

// MIN NUMBER FROM STACK A
int min_value(t_data *stack)
{
	int i = 0;

	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < stack->min)
		{
			stack->min = stack->stack_a[i];
		}
		i++;
	}

	return stack->min;
}
