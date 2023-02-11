/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:32:17 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 21:33:02 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack1, t_stack **stack2, char *print)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *stack1;
	temp2 = *stack2;
	*stack1 = (*stack1)->next;
	temp1->next = temp2;
	*stack2 = temp1;
	ft_printf("%s", print);
}

void	swap(t_stack **stack, char *print)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack;
	temp_b = (*stack)->next;
	*stack = temp_b;
	temp_a->next = temp_b->next;
	temp_b->next = temp_a;
	ft_printf("%s", print);
}

void	rotate(t_stack **stack, char *print)
{
	t_stack	*beg;
	t_stack	*end;

	beg = *stack;
	end = *stack;
	while (end->next)
		end = end->next;
	(*stack) = (*stack)->next;
	end->next = beg;
	beg->next = NULL;
	ft_printf("%s", print);
}

void	rev_rotate(t_stack **stack, char *print)
{
	t_stack	*node;
	t_stack	*end;

	end = *stack;
	node = *stack;
	while (node->next)
	{
		if (node->next->next == NULL)
			end = node;
		node = node->next;
	}
	node->next = *stack;
	end->next = NULL;
	*stack = node;
	ft_printf("%s", print);
}
