/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macudesarasqueta <macudesarasqueta@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:39:48 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/01 15:07:45 by macudesaras      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

//stack
typedef struct s_stack
{
	int				value;
	int				current_position;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}			t_stack;

//eliminar
//void	displayStack(t_stack *stack, char stackName);

// main
int		main(int argc, char **argv);

// Handle errors & free
void	free_all(t_stack **a, t_stack **b, int argc, char **argv);
void	ft_error(t_stack **a);
void	free_stack(t_stack **a);
void	free_arguments(char **argv);

// Stack initiation
void	ini_stack(t_stack **a, char **argv);
int		check_ifnum(char *str);
long	ft_atol(const char *str);
int		check_rep(t_stack *a, int num);
void	create_new_node(t_stack **stack, int num);

// Algorithms
void	small_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

// Algorithm sort
void	algorithm_sort(t_stack **a, t_stack **b);

// Iniciation nodes
void	ini_nodes(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_target_node(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);

// Move nodes
void	move_nodes(t_stack **a, t_stack **b);
t_stack	*return_cheapest(t_stack *stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	reverse_rota_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);

// Utils
int		stack_sorted(t_stack *a);
t_stack	*find_last_node(t_stack *node);
int		stack_len(t_stack *stack);
t_stack	*find_highest_node(t_stack *node);
t_stack	*find_lowest_node(t_stack *node);

// Instruction functions
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b);

#endif
