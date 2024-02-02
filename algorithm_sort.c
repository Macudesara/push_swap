/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:19:17 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/02 13:06:40 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		lena;

	lena = stack_len(*a);
	while (lena-- > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		ini_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_lowest_node(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, 1);
	else
		while (*a != smallest)
			rra(a, 1);
}
