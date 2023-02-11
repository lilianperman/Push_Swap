/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:19:52 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 22:09:53 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				position;
	struct s_stack	*next;
}	t_stack;

//utils:
void	put_error(void);
int		is_double(char **argv);
int		is_sorted(t_stack **stack);
void	valid_arg(char **argv);
long	push_atoi(const char *str);

//stack_handler:
void	clear_stack(t_stack **stack);
void	add_node(t_stack **list, int data, int index);
void	stack_order(t_stack **stack);

//sort_short:
void	sort_three(t_stack **stack);
void	sort_two(t_stack **stack);
void	sort_stack(int argc, t_stack **stack_a, t_stack **stack_b);
void	three_utils(t_stack **stack, int num1, int num2);

//sort_med:
int		find_min(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

//sort_big:
int		count_elements(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

//movements:
void	swap(t_stack **stack, char *print);
void	push(t_stack **stack1, t_stack **stack2, char *print);
void	rotate(t_stack **stack, char *print);
void	rev_rotate(t_stack **stack, char *print);

#endif
