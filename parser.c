/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:15:58 by crblanco          #+#    #+#             */
/*   Updated: 2026/03/09 14:08:01 by crblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

int	process_token(t_stack *stack, const char *token)
{
	if (!token)
	{
		handle_error(stack, NULL);
		return (0);
	}
	if (str_is_number(token) == 0)
		return (check_flags(stack, token));
	return (process_number(stack, token));
}

int	handle_error(t_stack *stack, char **tokens)
{
	print_error();
	if (tokens != NULL)
		free_split(tokens);
	if (stack != NULL)
		stack_clear(stack);
	return (0);
}

int	process_tokens_array(t_stack *stack, char **tokens)
{
	int	i;

	if (!tokens)
		return (0);
	i = 0;
	while (tokens[i] != NULL)
	{
		if (process_token(stack, tokens[i]) == 0)
		{
			free_split(tokens);
			return (0);
		}
		i++;
	}
	return (1);
}

int	split_and_process_argument(t_stack *stack, const char *arg)
{
	char	**tokens;
	int		result;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (handle_error(stack, NULL));
	if (tokens[0] == NULL)
		return (handle_error(stack, tokens));
	result = process_tokens_array(stack, tokens);
	free_split(tokens);
	return (result);
}

int	parse_arguments(t_stack *a, int argc, char **argv)
{
	int	i;

	if (argc <= 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (split_and_process_argument(a, argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
