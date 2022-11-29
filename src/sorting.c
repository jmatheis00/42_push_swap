/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:01:06 by jmatheis          #+#    #+#             */
/*   Updated: 2022/09/20 14:47:30 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_three(t_stack **stacka)
{
	int		a;
	int		b;
	int		c;

	a = getnode(*stacka, 0)->content;
	b = getnode(*stacka, 1)->content;
	c = getnode(*stacka, 2)->content;
	if (ftp_lstsize(stacka) && a < b && b > c && a < c)
	{
		sa(stacka);
		ra(stacka);
	}
	else if (ftp_lstsize(stacka) == 3 && a < b && b > c && a > c)
		rra(stacka);
	else if (ftp_lstsize(stacka) && a > b && b < c && a < c)
		sa(stacka);
	else if (ftp_lstsize(stacka) && a > b && b < c && a > c)
		ra(stacka);
	else if (ftp_lstsize(stacka) && a > b && b > c && a > c)
	{
		sa(stacka);
		rra(stacka);
	}
}

void	sort_five(t_stack **stacka, t_stack **stackb)
{
	int		pos_first;

	pos_first = 0;
	if (ftp_lstsize(stacka) == 2
		&& (*stacka)->content > (*stacka)->next->content)
	{
		ra(stacka);
		return ;
	}
	while (ftp_lstsize(stacka) > 3)
	{
		pos_first = getposbycontent(*stacka, smallest(stacka)->content);
		r_or_rr(stacka, (getposbycontent(*stacka, smallest(stacka)->content)),
			(ftp_lstsize(stacka) - 1 - pos_first), ftp_lstsize(stacka));
		pb(stacka, stackb);
	}
	if (ftp_lstsize(stacka) == 3)
		sort_three(stacka);
	while (*stackb != NULL)
		pa(stackb, stacka);
}

void	sort_hundred(t_stack **stacka, t_stack **stackb, t_help *help)
{
	int	count;

	count = 0;
	numbersperchunk(help);
	while (count < help->numofchunks)
	{
		onechunk(stacka, stackb, count, help->numbsperchunk);
		count++;
	}
	while (*stackb != NULL)
	{
		if (getposbycontent(*stackb, largest(stackb)->content)
			> ftp_lstsize(stackb) / 2)
		{
			while (largest(stackb)->content != (*stackb)->content)
				rrb(stackb);
		}
		else
		{
			while (largest(stackb)->content != (*stackb)->content)
				rb(stackb);
		}
		pa(stackb, stacka);
	}
}

int	is_sorted(t_stack **stacka, t_stack **stackb)
{
	int	i;

	i = 0;
	if (*stackb != NULL || *stacka == NULL)
		return (0);
	while (i < ftp_lstsize(stacka) - 1)
	{
		if (getnode(*stacka, i)->content > getnode(*stacka, i + 1)->content)
			return (0);
		i++;
	}
	return (1);
}

void	print_list(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
