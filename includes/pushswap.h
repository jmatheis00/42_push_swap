/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:41:33 by jmatheis          #+#    #+#             */
/*   Updated: 2022/09/20 16:10:34 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../lib/printf/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*sortedcopy;

}					t_stack;

typedef struct s_help
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_stack	*final;
	t_stack	*copy;
	t_stack	*sortedcopy;
	int		numbsperchunk;
	int		numofchunks;
}				t_help;

// INPUT HANDLING
int		checkerror(int argv, char **argc);
int		creatinglist(int argv, char **argc, t_stack **stack);
int		doublenumb(t_stack **stack);
int		intcheck(char *str);

// LIST FUNCTIONS
int		ftp_lstsize(t_stack **lst);
void	ftp_lstadd_front(t_stack **lst, t_stack *new);
void	ftp_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ftp_lstnew(int content);
t_stack	*ftp_lstlast(t_stack *lst);

// OPERATIONS
// swap
int		sa(t_stack **stack);
int		sb(t_stack **stack);
int		ss(t_stack **stacka, t_stack **stackb);
// rotate up
int		ra(t_stack **stack);
int		rb(t_stack **stack);
int		rr(t_stack **stacka, t_stack **stackb);
// rotate down
int		rra(t_stack **stack);
int		rrb(t_stack **stack);
int		rrr(t_stack **stacka, t_stack **stackb);
// push
int		pa(t_stack **fromb, t_stack **toa);
int		pb(t_stack **froma, t_stack **tob);

// FIND IN LIST
t_stack	*getnode(t_stack *stack, int pos);
int		getposbycontent(t_stack *stack, int content);
t_stack	*largest(t_stack **stacka);
t_stack	*smallest(t_stack **stacka);

// SORTING
void	sort_five(t_stack **stacka, t_stack **stackb);
void	sort_hundred(t_stack **stacka, t_stack **stackb, t_help *help);
int		is_sorted(t_stack **stacka, t_stack **stackb);
void	print_list(t_stack **stack);

// CHUNKS
void	numbersperchunk(t_help *help);
void	r_or_rr(t_stack **stacka, int pos_first, int pos_second, int size);
void	onechunk(t_stack **stacka, t_stack **stackb,
			int chunks, int numofchunk);
int		hold_first(t_stack **a, int chunks, int numofchunk);
int		hold_second(t_stack **a, int chunks, int numofchunk);

// TRANSFORMATION TO INDEX NUMBERS
void	finalstack(t_help *help);

#endif