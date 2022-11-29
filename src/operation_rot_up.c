/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:56:29 by jmatheis          #+#    #+#             */
/*   Updated: 2022/07/28 15:08:11 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ra(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return (-1);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ftp_lstadd_back(stack, tmp);
	ft_printf("ra\n");
	return (0);
}

int	rb(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return (-1);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ftp_lstadd_back(stack, tmp);
	ft_printf("rb\n");
	return (0);
}

int	rr(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	if (!stacka || !stackb)
		return (-1);
	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = NULL;
	ftp_lstadd_back(stacka, tmp);
	ft_printf("ra\n");
	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = NULL;
	ftp_lstadd_back(stackb, tmp);
	ft_printf("rr\n");
	return (0);
}
