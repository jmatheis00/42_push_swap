/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:30:58 by jmatheis          #+#    #+#             */
/*   Updated: 2023/08/11 14:54:47 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// 100 are splitted into 5 chunks and > 100 integers into 10 chunks.

void	numbersperchunk(t_help *help)
{
	int	size;
	int	numbs;
	int	chunks;

	numbs = 0;
	size = ftp_lstsize(&(help->final));
	if (size <= 100)
		numbs = size / 5;
	else if (size > 100)
		numbs = size / 10;
	chunks = size / numbs;
	if (size % numbs != 0)
		chunks += 1;
	help->numbsperchunk = numbs;
	help->numofchunks = chunks;
}

void	r_or_rr(t_stack **stacka, int pos_first, int pos_second, int size)
{
	if (pos_first <= pos_second)
	{
		while (pos_first > 0)
		{
			ra(stacka);
			pos_first--;
		}
	}
	else if (pos_first > pos_second)
	{
		pos_second = size - 1 - pos_second;
		while (pos_second < size)
		{
			rra(stacka);
			pos_second++;
		}
	}	
}

void	onechunk(t_stack **stacka, t_stack **stackb, int chunks, int numofchunk)
{
	int		pos_first;
	int		pos_second;
	int		count;
	int		size;

	count = 0;
	while (count < numofchunk && *stacka != NULL)
	{
		size = ftp_lstsize(stacka);
		pos_first = hold_first(stacka, chunks, numofchunk);
		pos_second = hold_second(stacka, chunks, numofchunk);
		r_or_rr(stacka, pos_first, pos_second, size);
		pb(stacka, stackb);
		if (smallest(stackb)->content == (*stackb)->content
			&& ftp_lstsize(stackb) > 1)
			rb(stackb);
		count++;
	}
}

int	hold_first(t_stack **a, int chunks, int numofchunk)
{
	int	position;

	position = 0;
	while (getnode(*a, position)->content
		> numofchunk - 1 + (numofchunk * chunks))
		position++;
	return (position);
}

int	hold_second(t_stack **a, int chunks, int numofchunk)
{
	int		startpos;
	int		position;

	startpos = ftp_lstsize(a) - 1;
	position = 0;
	while (getnode(*a, startpos)->content
		> numofchunk - 1 + (numofchunk * chunks))
	{
		startpos--;
		position++;
	}
	return (position);
}
