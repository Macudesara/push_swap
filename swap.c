/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:25:12 by mde-sara          #+#    #+#             */
/*   Updated: 2023/11/15 11:25:15 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	first;

	if (a == NULL || a->next == NULL)
		return ;
	if (stack_len(a) < 2)
		return ;
	first = a->value;
	a->value = a->next->value;
	a->next->value = first;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	first;

	if (b == NULL || b->next == NULL)
		return ;
	if (stack_len(b) < 2)
		return ;
	first = b->value;
	b->value = b->next->value;
	b->next->value = first;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
