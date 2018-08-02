# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 14:25:18 by pavaudon          #+#    #+#              #
#    Updated: 2018/05/17 14:25:19 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re norme

NAME_1		=	checker

SRC_DIR_1	=	./src/
SRCS_1		=	$(addprefix $(SRC_DIR_1),$(SRC_1))
SRC_1		=	ft_checker.c \
				ft_check_data.c \
				ft_data_fill.c \
				ft_application.c \
				ft_command.c \
				ft_print_stack.c

#SRC_DIR_2

OBJ_DIR_1	=	./obj_checker/
OBJS_1		=	$(addprefix $(OBJ_DIR_1),$(OBJ_1))
OBJ_1		=	$(SRC_1:.c=.o)

#OBJ_DIR_2

INC			=	./includes/
INCLIB		=	./libft/includes/
INCS		=	$(INC) $(INCLIB)

CC			=	gcc

CFLAGS		=	-Wextra -Wall -I$(INC) -I$(INCLIB)

all:			$(NAME_1)

#				$(NAME_2)

$(NAME_1):		$(OBJ_DIR_1) $(OBJS_1)
				@make -C libft/
				@$(CC) $(CFLAGS) $(OBJS_1) -o $(NAME_1) -L./libft -lft
				@echo "checker is made"

#$(NAME_2):

$(OBJ_DIR_1)%.o:	$(SRC_DIR_1)%.c $(INCS)
				@$(CC) $(CFLAGS) -c $< -o $@

#$(OBJ_DIR_2)%.o:

$(OBJ_DIR_1):
				@mkdir -p $(OBJ_DIR_1)

#$(OBJ_DIR_2):

clean:
				@rm -rf $(OBJS_1)
#				@rm -rf $(OBJS_2)
				@rm -rf $(OBJ_DIR_1)
#				@rm -rf $(OBJ_DIR_2)
				@make clean -C libft


fclean:			clean
				@rm -rf libft/libft.a
				@rm -rf $(NAME_1)
#				@rm -rf $(NAME_2)

re:			fclean all
