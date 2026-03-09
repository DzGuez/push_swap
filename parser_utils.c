/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:29:21 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/09 14:31:28 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	return ;
}

int	add_number_to_stack(t_stack *stack, int n)
{
	t_node	*node;

	if (!stack)
		return (handle_error(NULL, NULL));
	if (stack_has_duplicate(stack, n) == 1)
		return (handle_error(stack, NULL));
	node = create_node(n);
	if (!node)
		return (handle_error(stack, NULL));
	stack_push_back(stack, node);
	return (1);
}

int	process_number(t_stack *stack, const char *token)
{
	long	n;

	n = str_to_long(token);
	if (n < INT_MIN || n > INT_MAX)
	{
		handle_error(stack, NULL);
		return (0);
	}
	return (add_number_to_stack(stack, (int)n));
}

void	free_split(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	check_flags(t_stack *stack, const char *token)
{
	int	mode;

	if (stack->mode != 0)
		return (handle_error(stack, NULL));
	if (ft_strcmp(token, "--simple") == 0)
		mode = 1;
	else if (ft_strcmp(token, "--medium") == 0)
		mode = 2;
	else if (ft_strcmp(token, "--complex") == 0)
		mode = 3;
	else if (ft_strcmp(token, "--adaptive") == 0)
		mode = 4;
	else
		return (0);
	stack->mode = mode;
	return (1);
}
