/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:29:07 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/04 17:40:28 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	checksigns(char *argc, int j)
{
	if (ft_isdigit(argc[j]) == 0 && argc[j] != ' '
		&& argc[j] != '+' && argc[j] != '-')
		return (1);
	if (argc[j] == '+' || argc[j] == '-')
	{
		if (j != 0 && argc[j - 1] != ' ')
			return (1);
		j++;
		if (ft_isdigit(argc[j]) == 0)
			return (1);
	}
	return (0);
}

int	checkerror(int argv, char **argc)
{
	int	bool;
	int	i;
	int	j;

	i = 1;
	j = 0;
	bool = 0;
	while (i < argv)
	{
		while (argc[i][j] == ' ')
			j++;
		if (argc[i][j] == '\0')
			bool = 1;
		while (argc[i][j] != '\0')
		{
			if (checksigns(argc[i], j) == 1)
				bool = 1;
			j++;
		}
		j = 0;
		i++;
	}
	return (bool);
}

int	intmincheck(char *str, char *min)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str) - i < 10)
		return (0);
	else if (ft_strlen(str) - i > 10)
		return (1);
	while (str[i] != '\0' && min[j] != '\0')
	{
		if (str[i] < min[j])
			return (0);
		else if (str[i] > min[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	intmaxcheck(char *str, char *max)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str) - i < 10)
		return (0);
	else if (ft_strlen(str) - i > 10)
		return (1);
	while (str[i] != '\0' && max[j] != '\0')
	{
		if (str[i] < max[j])
			return (0);
		else if (str[i] > max[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	intcheck(char *str)
{
	char	*min;
	char	*max;

	min = "2147483648";
	max = "2147483647";
	if (*str == '-')
		return (intmincheck(str, min));
	else
		return (intmaxcheck(str, max));
	return (0);
}
