/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:24:24 by mde-sara          #+#    #+#             */
/*   Updated: 2024/01/11 00:23:18 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*end;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	end = find_last_node(*a);
	end->next = *a;
	*a = (*a)->next;
	end->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*end;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	end = find_last_node(*b);
	end->next = *b;
	*b = (*b)->next;
	end->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
