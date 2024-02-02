/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:40:31 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/01 15:07:34 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*end;
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	end = find_last_node(*a);
	temp = *a;
	while (temp->next != end)
		temp = temp->next;
	temp->next = NULL;
	end->next = *a;
	*a = end;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*end;
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	end = find_last_node(*b);
	temp = *b;
	while (temp->next != end)
		temp = temp->next;
	temp->next = NULL;
	end->next = *b;
	*b = end;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
