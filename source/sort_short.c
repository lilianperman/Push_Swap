/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:35:04 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 22:09:00 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **stack)
{
	swap(stack, "sa\n");
}

void	three_utils(t_stack **stack, int num1, int num2)
{
	if (num1 < num2)
		rev_rotate(stack, "rra\n");
	else
	{
		swap(stack, "sa\n");
		rev_rotate(stack, "rra\n");
	}
}

void	sort_three(t_stack **stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack)->data;
	num2 = (*stack)->next->data;
	num3 = (*stack)->next->next->data;
	if ((num1 < num2) && (num1 < num3) && (num2 > num3))
	{
		swap(stack, "sa\n");
		rotate(stack, "ra\n");
	}
	if ((num2 < num1) && (num2 < num3))
	{
		if (num1 < num3)
			swap(stack, "sa\n");
		else
			rotate(stack, "ra\n");
	}
	if ((num3 < num1) && (num3 < num2))
		three_utils(stack, num1, num2);
}

void	sort_stack(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc == 3)
		sort_two(stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc == 5)
		sort_four(stack_a, stack_b);
	else if (argc == 6)
		sort_five(stack_a, stack_b);
	else if (argc >= 7)
		radix_sort(stack_a, stack_b);
}
