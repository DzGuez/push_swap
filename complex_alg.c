/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:43:46 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/09 14:21:34 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	complex_alg(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(a->size - 1);
	while (max_bits != 0)
	{
		j = a->size;
		while (j--)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size > 0)
			pa(a, b);
		max_bits--;
		i++;
	}
}

static int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while (max >> bits != 0)
		bits++;
	return (bits);
}
