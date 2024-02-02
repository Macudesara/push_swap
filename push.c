/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:23:27 by mde-sara          #+#    #+#             */
/*   Updated: 2024/01/11 00:23:10 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*b_to_a;

	if (*b == NULL)
		return ;
	b_to_a = *b;
	*b = b_to_a->next;
	b_to_a->next = *a;
	*a = b_to_a;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*a_to_b;

	if (*a == NULL)
		return ;
	a_to_b = *a;
	*a = a_to_b->next;
	a_to_b->next = *b;
	*b = a_to_b;
	write(1, "pb\n", 3);
}
