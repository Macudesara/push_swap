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
#include <stdio.h>

/*int	main()
{
	t_stack *a;
	t_stack *ca;
	int		i;

	a = NULL;
	i = 0;
	create_new_node(&a, -4);
	create_new_node(&a, 8);
	create_new_node(&a, 9);

	ca = a;
	while (i < 5)
	{
		ca = a;
		while (ca)
		{
			printf("The node value is %d\n", ca->value);
			printf("The next node is %d\n\n", (ca->next != NULL) ? ca->next->value : -1);
			ca = ca->next;
		}
		ra(&a);
		i++;
	}
	while (a != NULL)
    {
        t_stack *temp = a;
        a = a->next;
        free(temp);
    }
	return (0);
}*/

/*void displayStack(t_stack *stack, char stackName)
{
	t_stack *current;
	current = stack;
	int len = 0;
	printf("\n");
	while (current != NULL)
	{
        	printf("%d\n", current->value);
        	current = current->next;
        	len++;
    }
	printf("%c\n\n", stackName);
}*/

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
	//displayStack(a, 'a');
	free_all(&a, &b, argc, argv);
	return (0);
}
