/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:37:24 by jotavare          #+#    #+#             */
/*   Updated: 2023/03/13 21:56:16 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "../header/push_swap.h"

// Returns the maximum value in the array
int find_max(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Returns the maximum value in the array
int find_min(int *array, int size)
{
    int min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

// Returns the number of elements in the bucket
int get_bucket_size(t_data *stack, int bucket_num)
{
    int size = 0;
    for (int i = 0; i < stack->size_b; i++)
    {
        if ((stack->stack_b[i] / 10) == bucket_num)
        {
            size++;
        }
    }
    return size;
}

// Returns the top element of the bucket
int get_bucket_top(t_data *stack, int bucket_num)
{
    int top = INT_MAX;
    for (int i = 0; i < stack->size_b; i++)
    {
        if ((stack->stack_b[i] / 10) == bucket_num && stack->stack_b[i] < top)
        {
            top = stack->stack_b[i];
        }
    }
    return top;
}

// Returns the index of the element in the array
int get_index(int *arr, int size, int elem)
{
    int i = 0;
    while (i < size)
    {
        if (arr[i] == elem)
        {
            return i;
        }
        i++;
    }
    return -1; // element not found
}

// Sorts the stack A using radix sort
void sort_radix(t_data *stack)
{
    int min;

    // Find minimum value in stack A
    min = find_min(stack->stack_a, stack->size_a);

    while (stack->size_a > 0)
    {
        // Push minimum value to stack B
        while (stack->stack_a[0] != min)
        {
            // if the second element is the minimum, swap it
            if (stack->stack_a[1] == min)
            {
                swap_a(stack, 1);
            }
            else if (get_index(stack->stack_a, stack->size_a, min) < (stack->size_a / 2))
            {
                rotate_a(stack, 1);
            }
            else
            {
                reverse_rotate_a(stack, 1);
            }
        }
        push_b(stack, 1);

        // Find next minimum value in stack A and push it to stack B
        min = find_min(stack->stack_a, stack->size_a);
    }

    // Push all values from stack B to stack A
    while (stack->size_b > 0)
    {
        push_a(stack, 1);
    }
}