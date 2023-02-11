/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:23:43 by liperman          #+#    #+#             */
/*   Updated: 2023/02/10 20:24:15 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cmp_str(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (i < n)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff != 0 || s1[i] == '\0')
			return (diff);
		i++;
	}
	return (0);
}
