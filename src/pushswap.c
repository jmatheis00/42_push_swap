/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:16:37 by jmatheis          #+#    #+#             */
/*   Updated: 2023/08/11 14:55:47 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argv, char **argc)
{
	t_help		help;

	ft_memset(&help, 0, sizeof(t_help));
	if (checkerror(argv, argc) == 1
		|| creatinglist(argv, argc, &help.stacka) == 1
		|| doublenumb(&help.stacka) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(&help.stacka, &help.stackb) == 1)
		return (0);
	if (ftp_lstsize(&help.stacka) <= 5)
		sort_five(&(help.stacka), &(help.stackb));
	else
	{
		finalstack(&help);
		sort_hundred(&(help.final), &(help.stackb), &help);
	}
	return (0);
}

/*
system("leaks push_swap");
if (is_sorted(&(help.final), &(help.stackb)))
	printf("sorted\n");
*/