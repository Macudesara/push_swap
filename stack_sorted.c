/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:33:46 by mde-sara          #+#    #+#             */
/*   Updated: 2023/11/24 09:31:28 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	stack_sorted(t_stack *a)
{
	//printf("Ha entrado a stack_sorted\n");
	if (!a)
		return (1);
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_stack **a)
{
	t_stack	*highest_node;

	//printf("Entra a la funcion sort_three, ya que len = 3\n");
	if (a == NULL || *a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return;
	highest_node = find_highest_node(*a);
	if (*a == highest_node)
	{
		ra(a);
		//displayStack(*a, 'a');
	}
	if ((*a)->next == highest_node)
	{
		rra(a);
		//displayStack(*a, 'a');
	}
	if ((*a)->value > (*a)->next->value)
		sa(*a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	int		min_value;
	int		i;

	printf("Ha ingresado a sort_five\n");
	i = 0;
	while (i < 2)
	{
		min_node = find_lowest_node(*a);
		printf("min_node value: %d\n", min_node->value);
		if (min_node == NULL)
			exit(1);
		min_value = min_node->value;
		if (min_node == rich_last_node(*a))
		{
			//printf("rich_last_node: %d\n", min_node->value);
			rra(a);
			pb(a, b);
			i++;
		}
		if ((*a)->value > min_value)
		{
			//displayStack(*a, 'a');
			//displayStack(*b, 'b');
			ra(a);
		}
		else
		{
			//displayStack(*a, 'a');
			//displayStack(*b, 'b');
			pb(a, b);
			//displayStack(*a, 'a');
            //displayStack(*b, 'b');
			i++;
		}
	}
	sort_three(a);
	//displayStack(*a, 'a');
    //displayStack(*b, 'b');
	pa(a, b);
	//displayStack(*a, 'a');
    //displayStack(*b, 'b');
	pa(a, b);
	//displayStack(*a, 'a');
    //displayStack(*b, 'b');
}