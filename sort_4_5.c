/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <crblanco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:28:25 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/04 13:58:49 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	find_min_value(t_stack *a)
{
	int		min;
	t_node	*node;

	node = a->top;
	min = node->value;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

static int	find_min_position(t_stack *a, int min)
{
	int		pos;
	t_node	*node;

	pos = 0;
	node = a->top;
	while (node)
	{
		if (node->value == min)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

static void	move_min_to_top(t_stack *a, int pos)
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

void	sort_4_5(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;
	int	to_push;

	if (a->size == 4)
		to_push = 1;
	else if (a->size == 5)
		to_push = 2;
	while (to_push--)
	{
		min = find_min_value(a);
		pos = find_min_position(a, min);
		move_min_to_top(a, pos);
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}
