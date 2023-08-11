# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 19:33:15 by jmatheis          #+#    #+#              #
#    Updated: 2023/08/11 14:56:23 by jmatheis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g #-fsanitize=address -g

FILES		= src/errors.c \
				src/input.c \
				src/chunks.c \
				src/find_in_list.c \
				src/listfunctions.c \
				src/operation_push.c \
				src/operation_rot_down.c \
				src/operation_rot_up.c \
				src/operation_swap.c \
				src/pushswap.c \
				src/sorting.c \
				src/transform.c

OBJ = $(FILES:.c=.o)

INCLUDES = src/pushswap.h

LIBS =	lib/printf/libftprintf.a \
		lib/libft/libft.a

PRINTF = lib/printf
LIBFT = lib/libft

# ************* #
#     RULES     #
# ************* #

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

lib/printf/libftprintf.a:
	@$(MAKE) -C $(PRINTF)

lib/libft/libft.a:
	@$(MAKE) -C $(LIBFT)

clean:
	rm -f src/*.o
	make fclean -C $(PRINTF)
	make fclean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re all