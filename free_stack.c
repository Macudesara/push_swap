/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:18:38 by mde-sara          #+#    #+#             */
/*   Updated: 2023/11/25 22:10:30 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_all(t_stack **a, t_stack **b, char**argv)
{
	if (a == NULL || !a)
		return ;
	else
	{
		free_stack(a);
		printf("hace el free_stack a\n");
	}
	if (b == NULL || !b)
		return ;
	else
	{
		free_stack(b);
		printf("hace el free_stack b\n");
	}
	if (argv != NULL)
		return ;
	else
	{
		free_arguments(argv);
		printf("hace el free_argv\n");
	}
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

	if (stack == NULL)
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
//exit 1 indica error, mientras que 0 indica que el programa se ejecutoo correctamente
void	ft_error(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit (1);
}
