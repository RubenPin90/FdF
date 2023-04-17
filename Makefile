# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <rpinchas@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:58:54 by rpinchas          #+#    #+#              #
#    Updated: 2023/04/17 13:56:29 by rpinchas         ###   ########.fr        #
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
SRC_F := test.c \
	load_map.c \
	system_ctl.c \
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


#RULES
all: ${NAME}

${NAME}: ${LIBFT} ${OBJ}
	@echo "${YELLOW}Compiling...${RESET}"
	${CC} ${CFLAGS} -o $@ ${OBJ} $< -Lminilibx-linux ${MLX_FLAGS} 
	@echo "${GREEN}Run Code${RESET}"

${OBJDIR}/%.o: ${SRCDIR}/%.c #obj_check
	${CC} ${CFLAG} ${DEBUG} -c $< -o $@

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
