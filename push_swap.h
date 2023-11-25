/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:39:48 by mde-sara          #+#    #+#             */
/*   Updated: 2023/11/25 22:07:18 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <unistd.h>
# include <limits.h>

//stack
typedef struct s_stack
{
	int		value;
	struct s_stack	*first;
	struct s_stack	*next;
}	t_stack;

//eliminar
//void	displayStack(t_stack *stack, char stackName);

// main
int	main(int argc, char **argv);

// Handle errors & free
void	free_all(t_stack **a, t_stack **b, char **argv);
void	ft_error(t_stack **stack);
void	free_stack(t_stack **a);
void	free_arguments(char **argv);

// Stack initiation
void	ini_stack(t_stack **a, char **argv);
int	check_ifnum(char *str);
long	ft_atol(const char *str);
int	check_rep(t_stack *a, int num);
void	create_new_node(t_stack **stack, int num);

// Algorithms
int	stack_sorted(t_stack *a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void 	sort_xnumbers(t_stack **a, t_stack **b);

// Utils
t_stack	*rich_last_node(t_stack *node);
int	stack_len(t_stack *stack);
t_stack	*find_highest_node(t_stack *node);
t_stack	*find_lowest_node(t_stack *node);
void	clean_b(t_stack **a, t_stack **b);
int	getMaxBits(t_stack *a);

// Instruction functions
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack *a, t_stack *b);

#endif
