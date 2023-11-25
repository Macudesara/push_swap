/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:27:11 by mde-sara          #+#    #+#             */
/*   Updated: 2023/11/25 13:07:52 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void displayStack(t_stack *stack, char stackName)
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
}

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
		else if (stack_len(a) == 3)
		{
			sort_three(&a);
			free_stack(&a);
		}
		else if (stack_len(a) == 5)
		{
			//displayStack(a, 'a');
            		//displayStack(b, 'b');
			sort_five(&a, &b);
			//displayStack(a, 'a');
            		//displayStack(b, 'b');
			free_all(&a, &b, argv);
		}
		else
		{
			sort_xnumbers(&a, &b);
			//free_all(&a, &b, argv);
		}
	}
	//displayStack(a, 'a');
	//free_all(&a, &b, argv);
	return (0);
}
