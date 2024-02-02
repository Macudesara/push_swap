/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:27:11 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/01 15:10:56 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ini_stack(&a, argv);
	}
	else
		ini_stack(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a);
		else if (stack_len(a) >= 3 && stack_len(a) <= 5)
			small_sort(&a, &b);
		else
			algorithm_sort(&a, &b);
	}
	free_all(&a, &b, argc, argv);
	return (0);
}
