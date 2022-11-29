/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:08 by jmatheis          #+#    #+#             */
/*   Updated: 2022/11/29 08:50:03 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s, int *counter)
{
	size_t	size;

	if (s == NULL)
	{
		write (1, "(null)", 6);
		*counter = *counter + 6;
		return ;
	}
	size = ft_strlen(s);
	write (1, s, size);
	*counter = *counter + size;
}
