/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:41:48 by crblanco          #+#    #+#             */
/*   Updated: 2026/02/26 15:51:28 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_stack(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	prev = stack->top;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse_stack(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_stack(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_stack(a);
	reverse_stack(b);
	ft_printf("rrr\n");
}
