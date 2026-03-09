/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_indixes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <crblanco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:42:37 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/04 13:43:36 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	create_indexes(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
