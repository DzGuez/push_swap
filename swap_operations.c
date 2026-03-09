/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:37:00 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/04 15:52:59 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = stack->top->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
}
