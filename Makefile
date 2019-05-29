# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelouarg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 10:55:39 by aelouarg          #+#    #+#              #
#    Updated: 2019/05/27 11:41:06 by aelouarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m
# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m
# Colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m

PROJECT 	= filler 
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
NAME		= aelouarg.filler
FILENAMES 	= place_token.c\
			  map_to_int.c\
			  main.c\
			  heat_algo.c
SRC_DIR		= src
SRC			= $(addprefix $(SRC_DIR)/, $(FILENAMES))
HDR 		= -I ./inc/filler.h
LIBFT		= src/libft/libft.a

all: $(NAME)

$(NAME):
	@make -C ./src/libft
	@$(CC) -o $(NAME) $(FLAGS) $(HDR) $(SRC) $(LIBFT)
	@echo "${_GREEN}${_BOLD}${_UNDER}$(NAME)${_END} created."
	@echo "${_BLUE}${_BOLD} "
	@echo ' ███████╗██╗██╗     ██╗     ███████╗██████╗'
	@echo ' ██╔════╝██║██║     ██║     ██╔════╝██╔══██╗'
	@echo ' █████╗  ██║██║     ██║     █████╗  ██████╔╝'
	@echo ' ██╔══╝  ██║██║     ██║     ██╔══╝  ██╔══██╗'
	@echo ' ██║     ██║███████╗███████╗███████╗██║  ██║'
	@echo ' ╚═╝     ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝'
	@echo "                              By : ${_GREEN}aelouarg${_END}"

clean:
	@make clean -C ./src/libft
	@echo "${_RED}${_BOLD}Cleaning $(PROJECT) objects.${_END}"

fclean: clean
	@make fclean -C ./src/libft
	@rm -f $(NAME)
	@echo "${_RED}${_BOLD}${_UNDER}$(NAME)${_END} deleted."

re: fclean all
