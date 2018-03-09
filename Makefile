# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 13:19:09 by pavaudon          #+#    #+#              #
#    Updated: 2018/03/09 13:19:11 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re norme

NAME_1		=	checker

SRC_DIR_1		=	./src/
SRCS_1		=	$(addprefix $(SRC_DIR_1),$(SRC_1))
SRC_1		=	ft_checker.c \
				ft_valide.c \
				ft_command.c

OBJ_DIR_1	=	./obj_checker/
OBJS_1		=	$(addprefix $(OBJ_DIR_1),$(OBJ_1))
OBJ_1		=	$(SRC_1:.c=.o)

INC			=	./includes/
INCLIB		=	./libft/includes/
INCS		=	$(INC) $(INCLIB)

CC			=	gcc

CFLAGS		=	-Wextra -Wall -I$(INC) -I$(INCLIB)

all:			$(NAME_1)

$(NAME_1):		$(OBJ_DIR_1) $(OBJS_1)
				make -C libft/
				$(CC) $(CFLAGS) $(OBJS_1) -o $(NAME_1) -L./libft -lft

$(OBJ_DIR_1)%.o:	$(SRC_DIR_1)%.c $(INCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_1):
				mkdir -p $(OBJ_DIR_1)

clean:
				rm -rf $(OBJS_1)
				make clean -C libft


fclean:			clean
				rm -rf libft/libft.a
				rm -rf $(NAME_1)

re:				fclean all
