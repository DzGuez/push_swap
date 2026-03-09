/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:38:42 by crblanco          #+#    #+#             */
/*   Updated: 2026/02/26 16:08:30 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || !b->top)
		return ;
	node = b->top;
	b->top = node->next;
	b->size--;
	node->next = a->top;
	a->top = node;
	a->size++;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !a->top)
		return ;
	node = a->top;
	a->top = node->next;
	a->size--;
	node->next = b->top;
	b->top = node;
	b->size++;
	ft_printf("pb\n");
}
