#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 00:00:08 by bchanot           #+#    #+#              #
#    Updated: 2016/10/18 11:27:25 by bchanot          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
FILES = main.c ps_display.c ps_take_arg.c ps_take_values.c ps_push_swap.c \
		ps_push.c ps_rules_p.c ps_rules_s.c ps_check.c ps_rules_r.c
SRC = $(addprefix srcs/, $(FILES))
OBJ = $(SRC:srcs/%.c=%.o)
FLAGS = -Wall -Werror -Wextra
LIB	= -L../libft -lft
INC	= -I./includes -I./libft/includes
NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
WARN_COLOR = \x1b[33;01m

all: $(NAME)

$(NAME): disp
	@echo  "\t---COMPILING OBJECTS---"
	@clang $(FLAGS) -c $(SRC) $(INC)
	@echo "$(OK_COLOR)\t---OBJECTS CREATED---$(NO_COLOR)"
	@echo  "\t---COMPILING EXECUTABLE---"
	@clang $(FLAGS) -o $(NAME) $(INC) $(OBJ) $(LIB)
	@echo  "$(OK_COLOR)\t---EXECUTABLE CREATED---"
	@echo  "---COMPILATION COMPLETE---$(NO_COLOR)"

disp:
	@echo  "$(WARN_COLOR)---PLEASE-WAIT---COMPILING--- $(NO_COLOR)"

clean:
	@/bin/rm -rf $(OBJ)
	@echo "$(OK_COLOR)---OBJECTS DELETED---$(NO_COLOR)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(OK_COLOR)---BINARY DELETED---$(NO_COLOR)"

re: fclean all
