/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:03:35 by jmatheis          #+#    #+#             */
/*   Updated: 2023/08/11 14:55:20 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ftp_lstnew(int content)
{
	t_stack	*temp;

	temp = NULL;
	temp = ft_calloc(1, sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}

t_stack	*ftp_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ftp_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ftp_lstlast(*lst);
		temp->next = new;
	}
}

void	ftp_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new == NULL && lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ftp_lstsize(t_stack **lst)
{
	int		counter;
	t_stack	*tmp;

	counter = 0;
	tmp = *lst;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}
