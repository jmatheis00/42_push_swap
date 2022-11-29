/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:51 by jmatheis          #+#    #+#             */
/*   Updated: 2022/07/27 17:57:21 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pb(t_stack **froma, t_stack **tob)
{
	t_stack	*tmp;

	if (!froma)
		return (-1);
	tmp = *froma;
	*froma = (*froma)->next;
	tmp->next = NULL;
	ftp_lstadd_front(tob, tmp);
	ft_printf("pb\n");
	return (0);
}

int	pa(t_stack **fromb, t_stack **toa)
{
	t_stack	*tmp;

	if (!fromb)
		return (-1);
	tmp = *fromb;
	*fromb = (*fromb)->next;
	tmp->next = NULL;
	ftp_lstadd_front(toa, tmp);
	ft_printf("pa\n");
	return (0);
}
