/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:58:38 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/14 02:05:02 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

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
		ps_free(args);
	}
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
	{
		simple_sort(stack_a, stack_b);
	}
	else
	{
		radix_sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
	{
		return (-1);
	}
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a) == 1)
	{
		exit (EXIT_SUCCESS);
	}
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_b = NULL;
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
