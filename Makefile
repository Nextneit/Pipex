# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:43:12 by ncruz-ga          #+#    #+#              #
#    Updated: 2023/11/20 15:59:57 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

PIPEX = pipex.a

LIB = ar rcs

SRCS = src/pipex.c src/pipex_utils.c src/split_quotes.c src/exec.c

OBJS = $(SRCS:.c=.o)

$(NAME):		$(OBJS) $(LIBFT)
					@$(LIB) $(PIPEX) $(OBJS)
					@$(CC) $(CFLAGS) $(PIPEX) $(LIBFT) -o $(NAME)

$(OBJS):		src/%.o : src/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
				@make -s -C $(LIBFT_PATH)

all: $(NAME)

clean:			@rm -f $(OBJS)
				@make clean -s -C $(LIBFT_PATH)

fclean:			@rm -f $(NAME) $(OBJS) $(LIBFT) $(PIPEX)

re: fclean all

pipe: all clean

.PHONY: all re fclean bonus