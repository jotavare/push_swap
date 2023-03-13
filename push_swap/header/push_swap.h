/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:13:54 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/13 19:00:24 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// LIBRARY
#include "../source/libft/libft.h"
#include "../source/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // BOOL DATA TYPE
#include <limits.h>	 // INT_MAX AND INT_MIN
#include <math.h>	 // POW

// MY STRUCT
typedef struct s_data
{
	int size_a;
	int size_b;
	int *stack_a;
	int *stack_b;
	int max;
	int min;
	int med;
} t_data;

// SORT OPERATIONS
void swap_a(t_data *stack, int check);
void swap_b(t_data *stack, int check);
void ss(t_data *stack, int check);
void push_a(t_data *stack, int check);
void push_b(t_data *stack, int check);
void rotate_a(t_data *stack, int check);
void rotate_b(t_data *stack, int check);
void rr(t_data *stack, int check);
void reverse_rotate_a(t_data *stack, int check);
void reverse_rotate_b(t_data *stack, int check);
void rrr(t_data *stack, int check);

// ALGORITHMS
void sort_two(t_data *stack);
void sort_three(t_data *stack);
void sort_five(t_data *stack);
void sort_radix(t_data *stack);

// UTILITIES
void free_all(t_data *stack);
void exit_error(t_data *stack);
int max_value(t_data *stack);
int min_value(t_data *stack);

// VALIDATION
int my_atoi(const char *str);
void check_min_max(int number);
void check_digit(int ac, char **av);
void check_sorted(t_data *stack);
void check_duplicates(t_data *stack);

#endif
