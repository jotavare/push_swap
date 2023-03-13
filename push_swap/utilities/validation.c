/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:31:12 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/07 23:40:17 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "../header/push_swap.h"

// ATOI THAT CHECKS INT_MAX AND INT_MIN
int my_atoi(const char *str)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		int digit = str[i] - '0';

		if (result > (INT_MAX - digit) / 10)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		result = result * 10 + digit;
		i++;
	}

	if (i >= 10 && sign == 1 && result > INT_MAX)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (i >= 10 && sign == -1 && result > -(INT_MIN + 1))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}

	return result * sign;
}

// CHECK FOR INT_MIN AND INT_MAX
void check_min_max(int number)
{
	if (number > INT_MAX || number < INT_MIN)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

// CHECK IF THE NUMBER IS A DIGIT
void check_digit(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
	}
}

// CHECK IF THE STACK IS SORTED
void check_sorted(t_data *stack)
{
	int i = 0;

	while (i < stack->size_a - 1)
	{
		if (stack->stack_a[i] >= stack->stack_a[i + 1])
		{
			return;
		}
		i++;
	}
	exit(EXIT_FAILURE);
}

// CHECK DUPLICATE NUMBERS
void check_duplicates(t_data *stack)
{
	bool duplicatesFound = false;
	int i = 0;
	while (i < stack->size_a - 1 && !duplicatesFound)
	{
		int j = i + 1;
		while (j < stack->size_a && !duplicatesFound)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				duplicatesFound = true;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack->size_b - 1 && !duplicatesFound)
	{
		int j = i + 1;
		while (j < stack->size_b && !duplicatesFound)
		{
			if (stack->stack_b[i] == stack->stack_b[j])
			{
				free_all(stack);

				duplicatesFound = true;
			}
			j++;
		}
		i++;
	}
	if (duplicatesFound)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
