/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:28:45 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/14 02:06:57 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

	/*
	Checks if a given integer is present in a given array of strings.
	Returns 1 if the integer is present and 0 otherwise.
	*/

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

	/*
	Checks if a given string represents a valid integer number.
	*/

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
	}
	if ((num[0] == '-' || num[0] == '+') && !num[1])
	{
		return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

	/*
	Takes a string argument av and splits it into an array of strings
	using the delimiter ' '. Returns the array of strings.
	*/

static char	**argc2(char *av)
{
	char	**args;

	args = ft_split(av, ' ');
	return (args);
}

	/*
	Checks the validity of the arguments passed to the program,
	which must be integers without duplicates and within the range
	of an int data type. It also handles the case when the arguments
	are passed as a single string separated by spaces.
	*/

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 1;
	if (argc == 2)
		args = argc2(argv[1]);
	else
		args = argv;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ps_error("Error");
		if (ft_contains(tmp, args, i) == 1)
			ps_error("Error");
		if (tmp < INT_MIN || tmp > 2147483647)
			ps_error("Error");
		i++;
	}
	if (argc == 2)
		ps_free(args);
}
