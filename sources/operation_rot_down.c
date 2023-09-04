/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rot_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:56:52 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/04 17:40:45 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	rra(t_stack **stack)
{
	t_stack	*tmplast;
	t_stack	*seclast;

	if (!stack)
		return (-1);
	tmplast = ftp_lstlast(*stack);
	seclast = *stack;
	while (seclast != NULL)
	{
		if (seclast->next->next == NULL)
			seclast->next = NULL;
		seclast = seclast->next;
	}
	ftp_lstadd_front(stack, tmplast);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_stack **stack)
{
	t_stack	*tmplast;
	t_stack	*seclast;

	if (!stack || !(*stack))
		return (-1);
	tmplast = ftp_lstlast(*stack);
	seclast = *stack;
	while (seclast && seclast->next)
	{
		if (seclast->next->next == NULL)
			seclast->next = NULL;
		seclast = seclast->next;
	}
	ftp_lstadd_front(stack, tmplast);
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmplast;
	t_stack	*seclast;

	if (!stacka || !stackb)
		return (-1);
	tmplast = ftp_lstlast(*stacka);
	seclast = *stacka;
	while (seclast != NULL)
	{
		if (seclast->next->next == NULL)
			seclast->next = NULL;
		seclast = seclast->next;
	}
	ftp_lstadd_front(stacka, tmplast);
	tmplast = ftp_lstlast(*stackb);
	seclast = *stackb;
	while (seclast != NULL)
	{
		if (seclast->next->next == NULL)
			seclast->next = NULL;
		seclast = seclast->next;
	}
	ftp_lstadd_front(stackb, tmplast);
	ft_printf("rrr\n");
	return (0);
}
