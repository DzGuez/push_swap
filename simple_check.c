/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:15:43 by crblanco          #+#    #+#             */
/*   Updated: 2026/02/24 14:39:56 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	str_is_number(const char *s)
{
	int	i;

	if (!s)
		return (0);
	if (s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0' || s[i] == '+' || s[i] == '-')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	stack_has_duplicate(t_stack *stack, int value)
{
	t_node	*current;
	int		count;

	if (!stack)
		return (0);
	current = stack->top;
	count = 0;
	while (current != NULL)
	{
		if (current->value == value)
			count++;
		if (count == 2)
			return (1);
		current = current->next;
	}
	return (0);
}

long	str_to_long(const char *s)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
