/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:25:39 by mde-sara          #+#    #+#             */
/*   Updated: 2023/11/23 14:12:18 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*rich_last_node(t_stack *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	printf("Ha entrado a stack_len\n");
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	printf("Len = %d\n", count);
	return (count);
}

t_stack	*find_highest_node(t_stack *node)
{
	long	max;
	t_stack	*max_node;

	if (!node)
		return (NULL);
	max = LONG_MIN;
	while (node)
	{
		if (node->value > max)
		{
			max = node->value;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

t_stack	*find_lowest_node(t_stack *node)
{
	int	min;
	t_stack	*min_node;

	//printf("Entro a la funcion find_lowest_node\n");
	if (node == NULL)
		return (NULL);
	min = INT_MAX;
	min_node = NULL;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}
