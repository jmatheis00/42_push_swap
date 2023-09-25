/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:16:37 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/25 14:56:06 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	free_stacka_stackb(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;

	while (*stacka)
	{
		temp = (*stacka)->next;
		free(*stacka);
		*stacka = temp;
	}
	while (*stackb)
	{
		temp = (*stackb)->next;
		free(*stackb);
		*stackb = temp;
	}
}

void	free_otherstacks(t_stack **final, t_stack **copy, t_stack **sortedcopy)
{
	t_stack	*temp;

	while (*final)
	{
		temp = (*final)->next;
		free(*final);
		*final = temp;
	}
	while (*copy)
	{
		temp = (*copy)->next;
		free(*copy);
		*copy = temp;
	}
	while (*sortedcopy)
	{
		temp = (*sortedcopy)->next;
		free(*sortedcopy);
		*sortedcopy = temp;
	}
}

int	main(int argv, char **argc)
{
	t_help		help;

	ft_memset(&help, 0, sizeof(t_help));
	if (checkerror(argv, argc) == 1
		|| creatinglist(argv, argc, &help.stacka) == 1
		|| doublenumb(&help.stacka) == 1)
	{
		write(2, "Error\n", 6);
		free_stacka_stackb(&help.stacka, &help.stackb);
		return (1);
	}
	if (is_sorted(&help.stacka, &help.stackb) == 0
		&& ftp_lstsize(&help.stacka) <= 5)
		sort_five(&(help.stacka), &(help.stackb));
	else if (is_sorted(&help.stacka, &help.stackb) == 0)
	{
		finalstack(&help);
		sort_hundred(&(help.final), &(help.stackb), &help);
	}
	free_stacka_stackb(&help.stacka, &help.stackb);
	free_otherstacks(&help.final, &help.copy, &help.sortedcopy);
	return (0);
}
