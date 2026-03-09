/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <crblanco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:34:48 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/04 16:56:20 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	simple(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
	{
		if (is_sorted(a))
			return ;
		if (a->size == 2)
			sort_2(a);
		else if (a->size == 3)
			sort_3(a);
		else if (a->size == 4 || a->size == 5)
			sort_4_5(a, b);
	}
	else
	{
		create_indexes(a);
		simple_alg(a, b);
	}
}
