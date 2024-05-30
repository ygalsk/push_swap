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

# Source and object directories
BINDIR   = bin

# Source files
SRCS     = $(wildcard ./*.c)

# Object files
OBJS     = $(SRCS:./%.c=$(BINDIR)/%.o)

# Header files
HEADER  = libft/libft.a

# Default target
all: $(NAME)

.SILENT:

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HEADER)
	echo $(GREEN)"Building $(NAME)"$(DEFAULT);

# Rule to compile source files to object files in the bin directory
$(BINDIR)/%.o: ./%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the bin directory if it does not exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Linking libft
$(HEADER):
	make -C libft

# Remove all object files
clean:
	rm -f $(BINDIR)/*.o
	make -C libft clean
	echo $(RED)"Removing $(NAME) object files"$(DEFAULT);

# Remove all files
fclean: clean
	rm -f $(NAME)
	rm -rf $(BINDIR)
	make -C libft fclean
	echo $(RED)"Removing $(NAME)"$(DEFAULT);

# Rebuild everything
re: fclean all
	echo $(GREEN)"Rebuilding everything"$(DEFAULT);

.PHONY: all clean fclean re

# Colours
DEFAULT = "\033[39m"
GREEN   = "\033[32m"
RED     = "\033[31m"
