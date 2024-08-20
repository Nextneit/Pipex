# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:43:12 by ncruz-ga          #+#    #+#              #
#    Updated: 2024/08/20 12:31:04 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

PIPEX = pipex.a

PIPEX_BONUS = pipex_bonus.a

LIB = ar rcs

SRCS = src/pipex.c src/pipex_utils.c src/exec.c src/split_quotes.c src/split_utils.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = srcb/pipex_bonus.c srcb/pipex_utils_bonus.c srcb/here_doc_bonus.c srcb/exec_bonus.c srcb/split_quotes_bonus.c srcb/split_utils_bonus.c srcb/exec_utils_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME):		$(OBJS) $(LIBFT)
					@$(LIB) $(PIPEX) $(OBJS)
					@$(CC) $(CFLAGS) $(PIPEX) $(LIBFT) -o $(NAME)

$(OBJS):		src/%.o : src/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS):	$(OBJS_BONUS) $(LIBFT)
				@$(LIB) $(PIPEX_BONUS) $(OBJS_BONUS)
				@$(CC) $(CFLAGS) $(PIPEX_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
				@make -s -C $(LIBFT_PATH)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:			
				@rm -f $(OBJS) $(OBJS_BONUS)
				@make clean -s -C $(LIBFT_PATH)

fclean:			
				@rm -f $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT) $(PIPEX) $(PIPEX_BONUS)
				@make fclean -s -C $(LIBFT_PATH)

re: fclean all

pipe: all clean

.PHONY: all re fclean clean bonus