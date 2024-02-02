/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:18:38 by mde-sara          #+#    #+#             */
/*   Updated: 2024/01/09 14:51:24 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **a, t_stack **b, int argc, char **argv)
{
	if (a != NULL || *a != NULL)
		free_stack(a);
	if (b == NULL || !*b)
		free_stack(b);
	if (argc == 2 && argv != NULL)
		free_arguments(argv);
}

void	free_arguments(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*now;

	if (stack == NULL || !stack)
		return ;
	now = *stack;
	while (now)
	{
		tmp = now->next;
		free(now);
		now = tmp;
	}
	*stack = NULL;
}

void	ft_error(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit (1);
}
