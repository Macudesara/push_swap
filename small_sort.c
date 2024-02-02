/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:06:47 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/01 12:46:59 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*highest_node;

	if (a == NULL || *a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return;
	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a, 1);
	if ((*a)->next == highest_node)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(*a);
}
void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	int		min_value;
	int		i;

	i = 0;
	while (i < 1)
	{
		min_node = find_lowest_node(*a);
		if (min_node == NULL)
			exit(1);
		min_value = min_node->value;
		if (min_node == find_last_node(*a))
			rra(a, 1);
		if ((*a)->value > min_value)
			ra(a, 1);
		else
		{
			pb(a, b);
			i++;
		}
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	int		min_value;
	int		i;

	i = 0;
	while (i < 2)
	{
		min_node = find_lowest_node(*a);
		if (min_node == NULL)
			exit(1);
		min_value = min_node->value;
		if (min_node == find_last_node(*a))
			rra(a, 1);
		if ((*a)->value > min_value)
			ra(a, 1);
		else
		{
			pb(a, b);
			i++;
		}
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void small_sort(t_stack **a, t_stack **b)
{
    if (stack_len(*a) == 3)
        sort_three(a);
	else if (stack_len(*a) == 4)
		sort_four(a, b);
	else if (stack_len(*a) == 5)
		sort_five(a, b);
}
