/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:58:38 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/14 08:16:15 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

	/*
	Initializes a stack by taking in arguments from the command line and
	creating a new node in the stack for each argument. If the argument is
	not provided from the command line, it takes the arguments from the argv
	parameter. Finally, it assigns an index to each node in the stack
	and returns the initialized stack.
	*/

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
	{
		free_string(args);
	}
}

	/*
	Checks the size of the input stack and uses either the simple
	sort or the radix sort algorithm to sort it. If the stack has
	5 or fewer elements, it uses the simple sort algorithm.
	Otherwise, it uses the radix sort algorithm to sort the stack.
	*/

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

	/*
	Takes integer inputs and sorts them using a stack data structure.
	Checks if there are enough arguments, initializes the stacks,
	sorts them, and then frees the memory used by the stacks.
	*/

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a) == 1)
		exit (EXIT_SUCCESS);
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_b = NULL;
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
