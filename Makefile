# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 13:27:47 by arigonza          #+#    #+#              #
#    Updated: 2024/01/27 17:46:16 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

CC := gcc

CFLAGS := -Wall -Werror -Wextra -pthread

LIBFT = lib/libft/libft.a

OBJDIR := obj

SRC = src/main.c src/parse.c src/utils.c \

OBJ = $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRC))

$(OBJDIR)/%.o : src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "$(YELLOW)Compiling philosophers...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ -I includes/
	@echo "$(GREEN)$(NAME) compiled.$(DEF_COLOR)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

clean :
	@echo "$(YELLOW)Deleting all object files..$(DEF_COLOR)"
	@rm -rf $(OBJDIR)
	@echo "$(RED)All object files deleted.$(DEF_COLOR)"

fclean : clean
	@echo "$(YELLOW)Deleting executable files..$(DEF_COLOR)"
	@rm -rf $(NAME)
	@echo "$(RED)Executables deleted.$(DEF_COLOR)"

re : fclean all

norm :
	@echo "$(CYAN)Norminette src/$(GREEN)"
	@norminette src/
	@echo "$(CYAN)Norminette includes/$(GREEN)"
	@norminette includes/
	@echo "$(DEF_COLOR)"

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m