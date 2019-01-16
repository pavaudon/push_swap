#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 00:02:23 by bchanot           #+#    #+#              #
#    Updated: 2016/10/11 07:56:28 by bchanot          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS =
SRC =
NAME = push
OBJ =
HEAD =
LIBFT =
NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
WARN_COLOR = \x1b[33;01m

$(NAME): all

all: checker push_swap

checker: lib
	@echo  "$(WARN_COLOR)\n------COMPILING CHECKER WAIT---\n$(NO_COLOR)"
	@make -C ./ps_checker/
	@cp ./ps_checker/checker .

push_swap: lib
	@echo  "$(WARN_COLOR)\n------COMPILING PUSH_SWAP WAIT---\n$(NO_COLOR)"
	@make -C ./ps_push_swap/
	@cp ./ps_push_swap/push_swap .

lib:
	@echo  "$(WARN_COLOR)------COMPILING LIBFT--- $(NO_COLOR)"
	@make -C ./libft/
	@echo  "$(OK_COLOR)------LIBFT COMPILE SUCCES--- $(NO_COLOR)"

clean:
	@make clean -C ./libft/
	@make clean -C ./ps_push_swap/
	@make clean -C ./ps_checker/

fclean: clean
	@make fclean -C ./libft/
	@make fclean -C ./ps_push_swap/
	@make fclean -C ./ps_checker/
	@/bin/rm -f checker
	@/bin/rm -f push_swap

re: fclean all
