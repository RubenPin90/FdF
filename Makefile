# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:58:54 by rpinchas          #+#    #+#              #
#    Updated: 2023/07/11 04:11:21 by rpinchas         ###   ########.fr        #
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
SRC := 	${addprefix ${SRCDIR}/, ${SRC_F}}

#OBJ FILES
OBJ_F :=  ${SRC_F:%.c=%.o}
OBJDIR := obj
OBJ :=	${addprefix ${OBJDIR}/, ${OBJ_F}}

#LIBRARIES
##Directories
LDIR := lib
LDIR_FT := ${LDIR}/libft
LDIR_MLX := ${LDIR}/mlx_linux
##Linking Libraries
INC := -I./inc -I./${LDIR_FT} -I./${LDIR_MLX} -I/usr/include
LIBMLX := -L./${LDIR_MLX} -lmlx_Linux
LIBX := -L/usr/lib -lXext -lX11 -lm
LIBFT := -L./${LDIR_FT} -lft
LIBS := ${LIBMLX} ${LIBX} ${LIBFT}

#RULES
all: ${NAME}

${NAME}: libs ${OBJ}
	@echo "${YELLOW}Compiling...${RESET}"
	${CC} ${CFLAGS} ${INC} ${OBJ} ${LIBS} -o $@
	@echo "${GREEN}Run Code${RESET}"

${OBJDIR}/%.o: ${SRCDIR}/%.c obj_check
	${CC} ${CFLAG} ${INC} -c $< -o $@

libs:
	@make -sC ${LDIR_FT}
	@make -sC ${LDIR_MLX} 

obj_check: 
	@echo "${BLUE}Making object files...${RESET}"
	@mkdir -p ${OBJDIR}

clean:
	@echo "${GREEN}Removing object files...${RESET}"
	@rm -f ${OBJ}
	@rm -rf ${OBJDIR}
	@make -sC ${LDIR_FT} clean
	@make -sC ${LDIR_MLX} clean
	@echo "${BLUE}DONE!${RESET}"

fclean: clean tclean
	@echo "${GREEN}Removing executables...${RESET}"
	@rm	-rf ${NAME}
	@make -C ${LDIR_FT} fclean -s
	@echo "${BLUE}DONE!${RESET}"

re: fclean all

tclean:
	@echo "${GREEN}Removing testfiles...${RESET}"
	@rm -f ${FILE}
	@echo "${BLUE}DONE!${RESET}"

.PHONY: all clean fclean re
