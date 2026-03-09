/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:09:30 by crblanco          #+#    #+#             */
/*   Updated: 2026/02/26 15:12:26 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*stack_to_array(t_stack *a)
{
	t_node	*node;
	int		*arr;
	int		i;

	if (!a)
		return (0);
	if (a->size == 0)
		return (0);
	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (0);
	node = a->top;
	i = 0;
	while (node != NULL)
	{
		arr[i] = node->value;
		i++;
		node = node->next;
	}
	return (arr);
}

double	count_disorder_pairs(int *arr, int n)
{
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	if (!arr || n < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			total_pairs = total_pairs + 1;
			if (arr[i] > arr[j])
				mistakes = mistakes + 1;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

double	compute_disorder(t_stack *a)
{
	int		n;
	int		*arr;
	double	disorder;

	if (!a)
		return (0.0);
	if (a->size < 2)
		return (0.0);
	n = a->size;
	arr = stack_to_array(a);
	if (!arr)
		return (0.0);
	disorder = count_disorder_pairs(arr, n);
	free(arr);
	return (disorder);
}
