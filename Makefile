# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opokusyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 12:03:39 by opokusyn          #+#    #+#              #
#    Updated: 2018/07/21 12:03:41 by opokusyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Werror

SRCS = main.c pipex.c path.c

LIBFT = placeholder

.PHONY = $(LIBFT)

BINS = $(SRCS:.c=.o)
all : $(LIBFT) $(NAME)

$(NAME) : $(BINS)
	gcc $(FLAGS) -o $@ $^ -Ilibft  -Llibft -lft

$(LIBFT):
	@make -C libft/

%.o:%.c
	gcc $(FLAGS) -c -o $@ $< -I includes/ -I libft/ 

clean:
	rm -rf $(BINS) $(BINS_LIB)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all
