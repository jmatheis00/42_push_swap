/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 00:54:25 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/04 17:40:31 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_stack	*getnode(t_stack *stack, int pos)
{
	if (pos < 0)
		return (NULL);
	while (pos)
	{
		if (stack == NULL)
			return (NULL);
		stack = stack->next;
		pos--;
	}
	return (stack);
}

int	getposbycontent(t_stack *stack, int content)
{
	int	i;
	int	size;

	size = ftp_lstsize(&stack);
	i = 0;
	while (size)
	{
		if (getnode(stack, i)->content == content)
			return (i);
		size--;
		i++;
	}
	return (-1);
}

t_stack	*smallest(t_stack **stacka)
{
	int		i;
	t_stack	*smallest;

	i = 1;
	smallest = *stacka;
	while (i < ftp_lstsize(stacka))
	{
		if (smallest->content > getnode(*stacka, i)->content)
			smallest = getnode(*stacka, i);
		i++;
	}
	return (smallest);
}

t_stack	*largest(t_stack **stacka)
{
	int		i;
	t_stack	*largest;

	i = 1;
	largest = *stacka;
	while (i < ftp_lstsize(stacka))
	{
		if (largest->content < getnode(*stacka, i)->content)
			largest = getnode(*stacka, i);
		i++;
	}
	return (largest);
}
