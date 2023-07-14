# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:58:54 by rpinchas          #+#    #+#              #
#    Updated: 2023/07/14 13:49:49 by rpinchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME := fdf
CFLAGS := -Werror -Wall -Wextra -g
CC := cc

#COLORS
GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RED := \033[31m
RESET := \033[0m

#SOURCE FILES
SRC_F := main.c \
	system_ctl.c \
	check_map.c \
	load_map.c \
	draw_map.c \
	draw_menu.c \
	control_key.c \
	actions.c \
	utils.c \
	exit.c
SRCDIR := src
SRC := 	$(addprefix $(SRCDIR)/, $(SRC_F))

#OBJ FILES
OBJ_F :=  $(SRC_F:%.c=%.o)
OBJDIR := obj
OBJ :=	$(addprefix $(OBJDIR)/, $(OBJ_F))

#LIBRARIES
##Directories
LDIR := lib
LDIR_FT := $(LDIR)/libft
LDIR_MLX := $(LDIR)/mlx_linux
LFTA = $(LDIR_FT)/libft.a
LMLX = $(LDIR_MLX)/libmlx_Linux.a
##Linking Libraries
INC := -I./inc -I./$(LDIR_FT) -I./$(LDIR_MLX) -I/usr/include
LIBMLX := -L./$(LDIR_MLX) -lmlx_Linux
LIBX := -L/usr/lib -lXext -lX11 -lm
LIBFT := -L./$(LDIR_FT) -lft
LIBS := $(LIBMLX) $(LIBX) $(LIBFT)

#RULES
all: $(LFTA) $(LMLX) $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling...$(RESET)"
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -o $@
	@echo "$(GREEN)Run Code$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAG) $(INC) -c $< -o $@

$(LFTA):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@make -sC $(LDIR_FT)

$(LMLX):
	@if [ ! -d $(LDIR_MLX) ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git lib/mlx_linux; fi
	@echo "$(YELLOW)Compiling MLX...$(RESET)"
	@make -sC $(LDIR_MLX)

clean:
	@echo "$(GREEN)Removing object files...$(RESET)"
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@make -sC $(LDIR_FT) clean
	@if [ -d $(LDIR_MLX) ]; then \
		make -sC $(LDIR_MLX) clean; fi
	@echo "$(BLUE)DONE!$(RESET)"

fclean: clean
	@echo "$(GREEN)Removing executables...$(RESET)"
	@rm	-rf $(NAME)
	@make -C $(LDIR_FT) fclean -s
	@echo "$(BLUE)DONE!$(RESET)"

re: fclean all

mlxclean: fclean
	@echo "$(GREEN)Removing mlx lib...$(RESET)"
	@rm -rf $(LDIR_MLX)
	@echo "$(BLUE)DONE!$(RESET)"

norm:
	@norminette $(SRC)
	@norminette $(LDIR_FT)
	@norminette inc

.PHONY: all clean fclean re mlxclean norm
