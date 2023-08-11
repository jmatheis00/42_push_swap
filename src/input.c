/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:49:27 by jmatheis          #+#    #+#             */
/*   Updated: 2023/08/11 14:55:11 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	arr_or_num(char *argc)
{
	char	bool;
	int		i;

	i = 0;
	bool = 'n';
	while (argc[i] != '\0')
	{
		if (argc[i] == ' ')
			bool = 'a';
		i++;
	}
	return (bool);
}

static int	numberstring(char *argc, t_stack **stack)
{
	char	**numbers;
	int		i;

	if (!argc || argc[0] == '\0')
		return (1);
	numbers = ft_split(argc, ' ');
	if (!numbers)
		return (1);
	i = 0;
	while (numbers[i])
	{
		if (intcheck(numbers[i]) != 0)
			return (1);
		ftp_lstadd_back(stack, ftp_lstnew(ft_atoi(numbers[i])));
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}

int	creatinglist(int argv, char **argc, t_stack **stack)
{
	int		i;

	i = 1;
	while (i < argv)
	{
		if (arr_or_num(argc[i]) == 'a')
		{
			if (numberstring(argc[i], stack) != 0)
				return (1);
		}
		if (arr_or_num(argc[i]) == 'n')
		{
			if (intcheck(argc[i]) != 0)
				return (1);
			ftp_lstadd_back(stack, ftp_lstnew(ft_atoi(argc[i])));
		}
		i++;
	}
	return (0);
}

int	doublenumb(t_stack **stack)
{
	t_stack	*tmp;
	int		size;
	int		s;
	int		j;

	tmp = *stack;
	size = ftp_lstsize(stack);
	s = 0;
	j = 1;
	while (s < size)
	{
		while (j < size)
		{
			if (getnode(*stack, s)->content == getnode(tmp, j)->content)
				return (1);
			j++;
		}
		s++;
		j = s + 1;
	}
	return (0);
}
