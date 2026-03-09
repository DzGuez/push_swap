/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:53:02 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/04 12:26:56 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_2(t_stack *a)
{
	int	x;
	int	y;

	if (!a)
		return ;
	if (a->size < 2)
		return ;
	x = a->top->value;
	y = a->top->next->value;
	if (x <= y)
		return ;
	if (x > y)
		sa(a);
}

static void	sort_3_cases(t_stack *a, int x, int y, int z)
{
	if (x > y && y < z && x < z)
		sa(a);
	if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	if (x > y && y < z && x > z)
		ra(a);
	if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	if (x < y && y > z && x > z)
		rra(a);
}

void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	if (!a || a->size < 3)
		return ;
	x = a->top->value;
	y = a->top->next->value;
	z = a->top->next->next->value;
	if (x <= y && y <= z)
		return ;
	sort_3_cases(a, x, y, z);
}
