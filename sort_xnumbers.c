/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_xnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:40:59 by mde-sara          #+#    #+#             */
/*   Updated: 2023/11/25 22:11:41 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_xnumbers(t_stack **a, t_stack **b) 
{
	int	maxBits;
	int	i;
	int	lenstack;
	int	j;
	int	n;
	int	temp;

	maxBits = getMaxBits(*a);
	i = -1;
	while (!stack_sorted(*a) && i++ < maxBits) 
	{
		lenstack = stack_len(*a);
		j = 0;
	while (j < lenstack) 
	{
		n = (*a)->value;
		temp = (n >> i) & 1;
		if (temp)
			ra(a);
		else
			pb(a, b);
		j++;
        }
	clean_b(a, b);
    }
}

int	getMaxBits(t_stack *a) 
{
	int	maxBits;
	int	num;
	int	bits;
	
	maxBits = 0;
	while (a != NULL) 
	{
		num = a->value;
		bits = 0;
		while (num != 0) 
		{
			bits++;
			num >>= 1; // Contar los bits del número
        	}
	if (bits > maxBits) 
		maxBits = bits;  // Actualizar el máximo de bits si es necesario
	a = a->next;
	}
	return (maxBits);
}

void	clean_b(t_stack **a, t_stack **b)
{
	int	count;
	
	count = stack_len(*b);
	while (count > 0)
	{
		pa(a, b);
		displayStack(*a, 'a');
		displayStack(*b, 'b');
		count--;
	}
	*b = NULL;
}
