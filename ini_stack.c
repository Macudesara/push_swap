/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:37:26 by mde-sara          #+#    #+#             */
/*   Updated: 2023/11/25 22:09:38 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ini_stack(t_stack **a, char **argv)
{
	long	num;

	while (*argv)
	{
		if (check_ifnum(*argv))
			ft_error(a);
		num = ft_atol(*argv);
		if (num < INT_MIN || num > INT_MAX)
			ft_error(a);
		if (check_rep(*a, (int)num))
			ft_error(a);
		create_new_node(a, (int)num);
		argv++;
	}
}

int	check_ifnum(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int	neg;
	long	res;

	neg = 1;
	res = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\f'
			|| *str == '\n' || *str == '\r' || *str == '\t'
			|| *str == '\v'))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * neg);
}

int	check_rep(t_stack *a, int num)
{
	if (a == NULL)
		return (0);
	while (a) // Loop until the end of stack 'a' is reached
	{
		if (a->value == num) //Check if the current node's value is equal to 'num'
			return (1);
		a = a->next; //Move to the next node to check for duplicates
	}
	return (0);
}

void	create_new_node(t_stack **stack, int num)
{
	t_stack	*new_node;

	if (stack == NULL)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		free(new_node);
		return ;
		//exit(1);
	}
	new_node->next = NULL;
	new_node->value = num;
	if (*stack == NULL) // If the stack is empty, the new_node becomes the first node
		*stack = new_node; 
	else // If the stack is not empty, find the last node and link the new_node
	{
		t_stack *current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
