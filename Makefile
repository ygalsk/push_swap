# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 14:54:45 by dkremer           #+#    #+#              #
#    Updated: 2024/04/19 15:22:01 by dkremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the binary
NAME     = push_swap

# Compiler and flags
CC       = cc
CFLAGS   = -Wall -Werror -Wextra -g

# Source files
SRCS     = $(wildcard ./*.c)

# Header files
HEADER  = libft/libft.a

# Object files
OBJS     = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Default target
all: $(NAME)

.SILENT:

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HEADER)
	echo $(GREEN)"Building $(NAME)"$(DEFAULT);

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Linking libft
$(HEADER):
	make -C libft

# Remove all object files
clean:
	rm -f $(OBJS)
	make -C libft clean
	echo $(RED)"Removing $(NAME) object files"$(DEFAULT);

# Remove all files
fclean: clean
	rm -f $(NAME)
	rm -rf MLX42
	make -C libft fclean
	echo $(RED)"Removing $(NAME)"$(DEFAULT);

# Rebuild everything
re: fclean all
	echo $(GREEN)"Rebuilding everything"$(DEFAULT);

re_bonus: fclean bonus
.PHONY: all clean fclean re

# Colours
DEFAULT = "\033[39m"
GREEN   = "\033[32m"
RED     = "\033[31m"
