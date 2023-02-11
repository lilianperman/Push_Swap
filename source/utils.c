/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:38:47 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 22:06:14 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_error(void)
{
	ft_printf("Error\n");
	exit (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*cpy;

	cpy = *stack;
	while (cpy->next)
	{
		if (cpy->data > cpy->next->data)
			return (0);
		cpy = cpy->next;
	}
	return (1);
}

long	push_atoi(const char *str)
{
	long	result;
	int		neg;

	neg = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = ((result * 10) + (*str - '0'));
		else
			put_error();
		str++;
	}
	result = result * neg;
	if (result > INT_MAX || result < INT_MIN)
		put_error();
	return (result);
}

int	is_double(char **argv)
{
	int	i;
	int	j;
	int	start1;
	int	start2;

	i = 1;
	start1 = 0;
	while (argv[i])
	{
		start2 = 0;
		j = i + 1;
		while (argv[j])
		{
			if (argv[i][0] == '+')
				start1 = 1;
			if (argv[j][0] == '+')
				start2 = 1;
			if (!cmp_str(&argv[i][start1], &argv[j][start2], 10))
				return (1);
			start1 = 0;
			j++;
		}
		i++;
	}
	return (0);
}

void	valid_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!push_isdigit(argv[i]))
			put_error();
		if (is_double(argv))
			put_error();
		i++;
	}
}
