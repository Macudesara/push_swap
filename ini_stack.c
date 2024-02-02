/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:37:26 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/01 13:01:28 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_new_node(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*current;

	if (stack == NULL)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = num;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

int	check_rep(t_stack *a, int num)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		neg;
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

int	check_ifnum(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if (*str == '+' || *str == '-' || *str == ' ')
		str++;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

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
