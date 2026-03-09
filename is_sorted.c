/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:33:26 by crblanco          #+#    #+#             */
/*   Updated: 2026/02/26 17:48:49 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return (1);
	if (stack->size < 2)
		return (1);
	node = stack->top;
	while (node->next != NULL)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
