/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:33:45 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 21:34:10 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	exit (0);
}

void	add_node(t_stack **list, int data, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->data = data;
	node->position = index;
	node->next = *list;
	*list = node;
}

void	stack_order(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*list;

	temp = *stack;
	list = *stack;
	while (list)
	{
		i = 1;
		while (temp)
		{
			if (list->data > temp->data)
				i++;
			temp = temp->next;
		}
		list->position = i;
		temp = *stack;
		list = list->next;
	}
}
