/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:53:18 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/04 17:40:51 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	sa(t_stack **stack)
{
	int	tmp;

	if (!stack)
		return (-1);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	ft_printf("sa\n");
	return (0);
}

int	sb(t_stack **stack)
{
	int	tmp;

	if (!stack)
		return (-1);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	ft_printf("sb\n");
	return (0);
}

int	ss(t_stack **stacka, t_stack **stackb)
{
	int	tmp;

	if (!stacka || !stackb)
		return (-1);
	tmp = (*stacka)->content;
	(*stacka)->content = (*stacka)->next->content;
	(*stacka)->next->content = tmp;
	tmp = (*stackb)->content;
	(*stackb)->content = (*stackb)->next->content;
	(*stackb)->next->content = tmp;
	ft_printf("ss\n");
	return (0);
}
