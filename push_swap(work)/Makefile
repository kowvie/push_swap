# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/06 09:39:18 by jsilva-r          #+#    #+#              #
#    Updated: 2026/08/13 16:00:35 by jsilva-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

SRCS= libft/ft_strlen.c src/algorithms/medium_2.c src/algorithms/medium.c \
src/algorithms/simple.c src/ops_stack/disorder.c src/ops_stack/free.c \
src/ops_stack/push.c src/ops_stack/reverse_rotate.c src/algorithms/complex.c \
src/ops_stack/rotate.c src/ops_stack/stack_create.c src/ops_stack/stack.c \
src/ops_stack/swap.c src/parsing/error.c src/parsing/parser.c src/utils/parser_utils.c \
src/utils/stack_utils.c main.c src/bench/bench.c src/bench/bench_utils.c libft/ft_putnbr.c \
libft/put_str.c src/algorithms/adaptive.c libft/split.c 

INCLUDES = -Iincludes

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

%.o: %.c
	cc -c $(FLAGS) $(INCLUDES) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
