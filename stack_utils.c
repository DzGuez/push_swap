/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <crblanco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:53:40 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/09 14:14:38 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->size = 0;
	stack->mode = 0;
}

t_node	*create_node(int n)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = n;
	node->next = NULL;
	node->index = -1;
	return (node);
}

t_node	*stack_last(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	stack_push_back(t_stack *stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->size++;
		return ;
	}
	last = stack_last(stack);
	last->next = new_node;
	stack->size++;
}

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->top = NULL;
	stack->size = 0;
}
