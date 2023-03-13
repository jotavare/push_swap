/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:36:57 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/08 03:15:44 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "header/push_swap.h"

// INICIALIZE MY STRUCT
void initialize_stack(t_data *stack, int ac)
{
	stack->size_a = ac - 1;
	stack->size_b = 0;
	stack->stack_a = (int *)ft_calloc(stack->size_a, sizeof(int));
	stack->stack_b = (int *)ft_calloc(ac, sizeof(int));
	stack->max = INT_MAX;
	stack->min = INT_MIN;
	stack->med = 0;
}

// FILL THE STACK A WITH VALUES
// CHECK IF NUMBER IS > INT_MAX OR < INT_MIN
void fill_stack(t_data *stack, int ac, char **av)
{
	int i;
	int j;
	long long int number;

	i = 0;
	j = 1;
	while (j < ac)
	{
		check_digit(ac, av);
		number = my_atoi(av[j]);
		check_min_max(number);
		stack->stack_a[i] = number;
		i++;
		j++;
	}
}

// MAIN
// CHECK NUMBER OF ARGUMENTS
// INITIALIZE, FILL, CHECK & PRINT
int main(int ac, char **av)
{
	t_data stack;

	initialize_stack(&stack, ac);
	fill_stack(&stack, ac, av);
	check_sorted(&stack);
	check_duplicates(&stack);

	// CHECK NO PARAMETERS
	if (ac <= 2)
	{
		exit(EXIT_FAILURE);
	}

	// SORT ALGORITHMS
	if (stack.size_a <= 2)
		sort_two(&stack);
	else if (stack.size_a == 3)
		sort_three(&stack);
	else if (stack.size_a <= 5)
		sort_five(&stack);
	else
	{
		sort_radix(&stack);
	}

	/*
	// PRINTF
	ft_printf("-------\n");
	while (index < stack.size_a)
	{
		ft_printf("%d\n", stack.stack_a[index]);
		index++;
	}
	ft_printf("-------\n");
	ft_printf("Stack A\n");

	ft_printf("-------\n");
	while (index < stack.size_b)
	{
		ft_printf("%d\n", stack.stack_b[index]);
		index++;
	}
	ft_printf("-------\n");
	ft_printf("Stack B\n");
	*/

	free(stack.stack_a);
	free(stack.stack_b);
	return (EXIT_SUCCESS);
}
