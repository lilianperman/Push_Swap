/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:38:00 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 21:38:14 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_elements(t_stack **stack)
{
	t_stack	*cpy;
	int		i;

	cpy = *stack;
	i = 0;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	return (i);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	bin;

	bin = 0;
	while (!(is_sorted(stack_a)))
	{
		count = count_elements(stack_a);
		while (count)
		{
			if ((*stack_a)->position & (1 << bin))
				rotate(stack_a, "ra\n");
			else
				push(stack_a, stack_b, "pb\n");
			count--;
		}
		bin++;
		while (*stack_b)
			push(stack_b, stack_a, "pa\n");
	}
}
