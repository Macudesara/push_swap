/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:57:14 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/01 15:12:08 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	set_cheapest(t_stack *b)
{
	long			best_match_value;
	t_stack	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	set_price(t_stack *a, t_stack *b) //how many moves to bring to the top
{
	int	lena;
	int	lenb;

	lena = stack_len(a);
	lenb = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = lenb - (b->current_position); // b->push_price += lenb - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += lena - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX; // 9223372036854775807
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_lowest_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_current_position(t_stack *stack)
{
	int	node_position;
	int	center_line;

	node_position = 0;
	if (stack == NULL)
		return ;
	center_line = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = node_position;
		if (node_position <= center_line)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		node_position++;
	}
	//printf("center_line1 %d\n", center_line);
}

void	ini_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
