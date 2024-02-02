/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:19:17 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/01 14:56:01 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	algorithm_sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		lena;

	lena = stack_len(*a);
	while (lena-- > 3)
		pb(a, b);
	sort_three(a);
	// printf("Ha salido del sort_three\n");
	// displayStack(*a, 'a');
	// displayStack(*b, 'b');
	while (*b)
	{
		ini_nodes(*a, *b);
		//printf("ini_nodes ok\n");
		move_nodes(a, b);
		//printf("move_nodes ok\n");
	}
	set_current_position(*a);
	smallest = find_lowest_node(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
	// displayStack(*a, 'a');
	// displayStack(*b, 'b');
}
