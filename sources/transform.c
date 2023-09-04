/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:37:53 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/04 17:40:58 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	deletenode(t_stack **stack, int con)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = *stack;
	if (tmp != NULL && tmp->content == con)
	{
		*stack = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL && tmp->content != con)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	free(tmp);
}

static void	sortcopy(t_help *help)
{
	int		size;
	int		i;
	int		j;

	i = 0;
	while (i < ftp_lstsize(&(help->stacka)))
	{
		ftp_lstadd_back(&(help->copy),
			ftp_lstnew(getnode(help->stacka, i)->content));
		i++;
	}
	i = 0;
	size = ftp_lstsize(&(help->copy));
	while (i < size)
	{
		j = getposbycontent(help->copy, smallest(&(help->copy))->content);
		ftp_lstadd_back(&(help->sortedcopy),
			ftp_lstnew(getnode(help->copy, j)->content));
		deletenode(&(help->copy), smallest(&(help->copy))->content);
		i++;
	}
}

// kleinsten Wert finden, numb setzen
// Pos 1 von A wird die Nummer der Pos von A sorted in Final
void	finalstack(t_help *help)
{
	int		i;
	int		s;

	sortcopy(help);
	s = 0;
	while (s < ftp_lstsize(&(help->stacka)))
	{
		i = 0;
		while (getnode(help->stacka, s)->content
			!= getnode(help->sortedcopy, i)->content)
			i++;
		ftp_lstadd_back(&(help->final), ftp_lstnew(i));
		s++;
	}
}
