# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 19:33:15 by jmatheis          #+#    #+#              #
#    Updated: 2023/09/04 17:41:59 by jmatheis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g #-fsanitize=address -g

SRCS		= errors.c \
				input.c \
				chunks.c \
				find_in_list.c \
				listfunctions.c \
				operation_push.c \
				operation_rot_down.c \
				operation_rot_up.c \
				operation_swap.c \
				pushswap.c \
				sorting.c \
				transform.c
HEADER 		= pushswap.h

M_SRCS		= $(addprefix ./sources/, $(SRCS))
M_HEADER	= $(addprefix ./includes/, $(HEADER))

OBJ = $(M_SRCS:%.c=%.o)

LIBS =	lib/printf/libftprintf.a \
		lib/libft/libft.a

PRINTF = lib/printf
LIBFT = lib/libft

# ************* #
#     RULES     #
# ************* #

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c $(M_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

lib/printf/libftprintf.a:
	@$(MAKE) -C $(PRINTF)

lib/libft/libft.a:
	@$(MAKE) -C $(LIBFT)

clean:
	rm -f $(OBJ)
	make fclean -C $(PRINTF)
	make fclean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re all