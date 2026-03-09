/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <crblanco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:03 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/04 14:34:06 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	t_node	*node;
	int		min;

	node = a->top;
	min = node->index;
	while (node)
	{
		if (node->index < min)
			min = node->index;
		node = node->next;
	}
	return (min);
}

static int	find_min_index_pos(t_stack *a, int min)
{
	t_node	*node;
	int		pos;

	pos = 0;
	node = a->top;
	while (node)
	{
		if (node->index == min)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

static void	move_min_to_top_index(t_stack *a, int pos)
{
	int	steps;

	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		steps = a->size - pos;
		while (steps-- > 0)
			rra(a);
	}
}

void	simple_alg(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	while (a->size > 0)
	{
		min = find_min_index(a);
		pos = find_min_index_pos(a, min);
		rotate_min_to_top_index(a, pos);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
