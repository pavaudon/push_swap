# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 14:25:18 by pavaudon          #+#    #+#              #
#    Updated: 2019/03/21 19:02:00 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re norme

NAME_1		=	checker

SRC_DIR_1	=	./src/
SRC_1			=	ft_checker.c \
						ft_check_data.c \
						ft_stack_fill.c \
						ft_is_again.c \
						ft_application.c \
						ft_s_p_command.c \
						ft_r_rr_command.c

SRCS_1		=	$(addprefix $(SRC_DIR_1),$(SRC_1))

#SRC_DIR_2

OBJ_DIR_1	=	./obj_checker/
OBJS_1		=	$(addprefix $(OBJ_DIR_1),$(OBJ_1))
OBJ_1			=	$(SRC_1:.c=.o)

#OBJ_DIR_2

INC				=	./includes/
INCLIB		=	./libft/includes/
INCS			=	$(INC) $(INCLIB)

CC				=	gcc

CFLAGS		=	-Wextra -Werror -Wall -I$(INC) -I$(INCLIB) -g

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
