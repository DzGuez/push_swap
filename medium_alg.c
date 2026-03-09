/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:17:09 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/09 14:23:16 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	has_index_in_range(t_stack *a, int low, int high)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->index >= low && node->index <= high)
			return (1);
		node = node->next;
	}
	return (0);
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, int low, int high)
{
	int	mid;

	mid = (low + high) / 2;
	while (has_index_in_range(a, low, high))
	{
		if (a->top->index >= low && a->top->index <= high)
		{
			pb(a, b);
			if (b->top->index < mid)
				rb(b);
		}
		else
			ra(a);
	}
}

static void	process_chunk(t_stack *a, t_stack *b, int chunk, int chunk_count)
{
	int	low;
	int	high;
	int	size;
	int	chunk_size;

	size = a->size;
	chunk_size = size / chunk_count;
	low = chunk * chunk_size;
	if (chunk == chunk_count - 1)
		high = size - 1;
	else
		high = (chunk + 1) * chunk_size - 1;
	push_chunk_to_b(a, b, low, high);
}

void	medium_alg(t_stack *a, t_stack *b)
{
	int	size;
	int	chunk_count;
	int	chunk;

	size = a->size;
	if (size <= 5)
		return ;
	if (size <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;
	chunk = 0;
	while (chunk < chunk_count)
	{
		process_chunk(a, b, chunk, chunk_count);
		chunk++;
	}
	push_back_to_a(a, b);
}
