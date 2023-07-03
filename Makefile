# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rubsky <rubsky@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:58:54 by rpinchas          #+#    #+#              #
#    Updated: 2023/06/30 15:02:16 by rubsky           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME := fdf	
HEAD := fdf.h
CFLAGS := -Werror -Wall -Wextra
MLX_FLAGS := -lX11 -lXext -lmlx
DEBUG := -g
CC := clang

#FILES
SRCDIR := src
SRC_F := main.c \
	load_map.c \
	system_ctl.c \
	draw_map.c \
	draw_map2.c \
	control_key.c \
	control_mouse.c \
	control_util.c \
	exit.c
SRC := 	${addprefix ${SRCDIR}/, ${SRC_F}}
OBJDIR := obj
OBJ_F :=  ${SRC_F:%.c=%.o}
OBJ :=	${addprefix ${OBJDIR}/, ${OBJ_F}}

#LIBFT
LIBFTDIR := libft
LIBFT_F := libft.a
LIBFT := ${addprefix ${LIBFTDIR}/, ${LIBFT_F}}

#COLORS
GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RED := \033[31m
RESET := \033[0m
# Define the directories for the header files and libraries
HEADER_DIR =
LIB_DIR =

# Check if mlx.h is installed and set the appropriate include flag
ifeq ($(shell test -f /usr/include/X11/mlx.h && echo 1),1)
	HEADER_DIR = /usr/include/X11
	LIB_DIR = /usr/lib/X11
else
	HEADER_DIR = ./minilibx-linux
	LIB_DIR = ./minilibx-linux
endif
LHEAD = -I${HEADER_DIR}
LIB = -L${LIB_DIR}

#RULES
all: ${NAME}

${NAME}: ${LIBFT} ${OBJ}
	@echo "${YELLOW}Compiling...${RESET}"
	${CC} ${CFLAGS} -o $@ ${OBJ} $< ${HEAD} ${LIB} ${MLX_FLAGS} -lm 
	@echo "${GREEN}Run Code${RESET}"

${OBJDIR}/%.o: ${SRCDIR}/%.c obj_check
	${CC} ${CFLAG} ${DEBUG} ${LHEAD} -c $< -o $@

obj_check: 
	@echo "${BLUE}Making object files...${RESET}"
	@mkdir -p ${OBJDIR}

${LIBFT}: ${LIBFTDIR}
	@make -C $^ -s

clean:
	@echo "${GREEN}Removing object files...${RESET}"
	@rm -f ${OBJ}
	@rm -rf ${OBJDIR}
	@make -C ${LIBFTDIR} clean -s
	@echo "${BLUE}DONE!${RESET}"

fclean: clean tclean
	@echo "${GREEN}Removing executables...${RESET}"
	@rm	-rf ${NAME}
	@make -C ${LIBFTDIR} fclean -s
	@echo "${BLUE}DONE!${RESET}"

re: fclean all

tclean:
	@echo "${GREEN}Removing testfiles...${RESET}"
	@rm -f ${FILE}
	@echo "${BLUE}DONE!${RESET}"

.PHONY: all clean fclean re
