/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:37:24 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/07 23:40:10 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "../header/push_swap.h"

int get_min_index(int *arr, int size)
{
    int min_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}

void sort_two(t_data *stack)
{
    if (stack->stack_a[0] > stack->stack_a[1])
    {
        swap_a(stack, 1);
    }
}

void sort_three(t_data *stack)
{
    if (stack->stack_a[1] > stack->stack_a[0] && stack->stack_a[1] > stack->stack_a[2])
    {
        if (stack->stack_a[0] > stack->stack_a[2])
        {
            reverse_rotate_a(stack, 1);
        }
        else
        {
            reverse_rotate_a(stack, 1);
            swap_a(stack, 1);
        }
    }
    else if (stack->stack_a[1] < stack->stack_a[0] && stack->stack_a[1] < stack->stack_a[2])
    {
        if (stack->stack_a[0] > stack->stack_a[2])
        {
            rotate_a(stack, 1);
        }
        else
        {
            swap_a(stack, 1);
        }
    }
    else
    {
        if (stack->stack_a[0] < stack->stack_a[2])
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            swap_a(stack, 1);
            reverse_rotate_a(stack, 1);
        }
    }
}

void sort_five(t_data *stack)
{
    if (stack->size_a == 2)
    {
        if (stack->stack_a[0] > stack->stack_a[1])
        {
            swap_a(stack, 1);
        }
    }
    else if (stack->size_a == 3)
    {
        if (stack->stack_a[0] > stack->stack_a[1])
        {
            swap_a(stack, 1);
        }
        if (stack->stack_a[1] > stack->stack_a[2])
        {
            reverse_rotate_a(stack, 1);
        }
        if (stack->stack_a[0] > stack->stack_a[1])
        {
            swap_a(stack, 1);
        }
    }
    else if (stack->size_a == 4)
    {
        int min_index = get_min_index(stack->stack_a, stack->size_a);
        while (min_index != 0)
        {
            if (min_index <= stack->size_a / 2)
            {
                rotate_a(stack, 1);
            }
            else
            {
                reverse_rotate_a(stack, 1);
            }
            min_index = get_min_index(stack->stack_a, stack->size_a);
        }
        push_b(stack, 1);
        sort_five(stack);
        push_a(stack, 1);
        if (stack->stack_a[0] > stack->stack_a[1])
        {
            swap_a(stack, 1);
        }
    }
    else if (stack->size_a == 5)
    {
        int min_index;
        while (stack->size_b < 2)
        {
            min_index = get_min_index(stack->stack_a, stack->size_a);
            while (min_index != 0)
            {
                if (min_index <= stack->size_a / 2)
                {
                    rotate_a(stack, 1);
                }
                else
                {
                    reverse_rotate_a(stack, 1);
                }
                min_index = get_min_index(stack->stack_a, stack->size_a);
            }
            push_b(stack, 1);
        }
        sort_five(stack);
        push_a(stack, 1);
        push_a(stack, 1);
        if (stack->stack_a[0] > stack->stack_a[1])
        {
            swap_a(stack, 1);
        }
    }
}
