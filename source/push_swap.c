/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:46:03 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 21:47:17 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = argc;
	if (argc > 1)
	{
		valid_arg(argv);
		while (i > 1)
		{
			num = push_atoi(argv[--i]);
			add_node(&stack_a, num, 0);
		}
		stack_order(&stack_a);
		if (is_sorted(&stack_a))
			clear_stack(&stack_a);
		sort_stack(argc, &stack_a, &stack_b);
		clear_stack(&stack_a);
	}
}
