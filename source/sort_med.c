/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:36:48 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 21:37:35 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack **stack)
{
	t_stack	*list;
	int		min;

	list = *stack;
	min = list->data;
	while (list->next)
	{
		if (list->next->data < min)
			min = list->next->data;
		else
			list = list->next;
	}
	return (min);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	if (!(is_sorted(stack_a)))
	{
		min = find_min(stack_a);
		while ((*stack_a)->data != min)
			rev_rotate(stack_a, "rra\n");
		push(stack_a, stack_b, "pb\n");
		sort_three(stack_a);
		push(stack_b, stack_a, "pa\n");
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*node;

	node = *stack_a;
	min = find_min(stack_a);
	while (node->next)
		node = node->next;
	if (node->data == min)
	{
		rev_rotate(stack_a, "rra\n");
		push(stack_a, stack_b, "pb\n");
		sort_four(stack_a, stack_b);
		push(stack_b, stack_a, "pa\n");
	}
	else
	{
		while ((*stack_a)->data != min)
			rotate(stack_a, "ra\n");
		push(stack_a, stack_b, "pb\n");
		sort_four(stack_a, stack_b);
		push(stack_b, stack_a, "pa\n");
	}
}
