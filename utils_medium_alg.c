/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium_alg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:20:37 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/09 13:38:01 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_max_index_b(t_stack *b)
{
	t_node	*node;
	int		max;

	node = b->top;
	max = node->index;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}

static int	get_max_pos_b(t_stack *b, int max)
{
	t_node	*node;
	int		pos;

	node = b->top;
	pos = 0;
	while (node)
	{
		if (node->index == max)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

static void	rotate_max_to_top_b(t_stack *b, int pos)
{
	int	steps;

	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		steps = b->size - pos;
		while (steps-- > 0)
			rrb(b);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	pos;

	while (b->size > 0)
	{
		max = get_max_index_b(b);
		pos = get_max_pos_b(b, max);
		rotate_max_to_top_b(b, pos);
		pa(a, b);
	}
}
