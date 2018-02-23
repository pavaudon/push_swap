# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 12:19:38 by pavaudon          #+#    #+#              #
#    Updated: 2018/02/08 13:29:22 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

NAME1 = 					checker

NAME2 = 					push_swap

CC = 							gcc
CFLAGS = 					-Wall -Werror -Wextra -I$(INC_DIR)

SRC_DIR =					./src/
SRC_1 = 					ft_checker.c\

SRC_2 =  					ft_push_swap.c\

SRCS_1 =					$(addprefix $(SRC_DIR),$(SRC_1))

SRCS_2 = 					$(addprefix $(SRC_DIR,$(SRC_2)))

OBJ_DIR_1 =				./obj_1/
OBJ_1 = 					$(SRC_1:.c=.o)
OBJS_1 =					$(addprefix $(OBJ_DIR),$(OBJ))

OBJ_DIR_2 =				./obj_2/
OBJ_2 = 					$(SRC_2:.c=.o)
OBJS_2 =					$(addprefix $(OBJ_DIR),$(OBJ))

INC_DIR =					./includes/
INC =							push_swap.h
INCS =						$(addprefix $(INC_DIR),$(INC))

all : 						$(NAME_1) $(NAME_2)

$(NAME_1) :				$(OBJ_DIR_1) $(OBJS_1)
									@ar rc $(NAME_1) $(OBJS_1)
									@ranlib $(NAME_1)
									echo ""$(NAME_1)" appeared"

$(NAME_2) :				$(OBJ_DIR_2) $(OBJS_2)
									@ar rc $(NAME_2) $(OBJS_2)
									@ranlib $(NAME_2)
									echo ""$(NAME_2)" appeared"

$(OBJ_DIR_1)%.o:	$(SRC_DIR_1)%.c $(INCS)
									@$(CC) $(CFLAGS) -c $< -o $@
									echo "*MAGIC IN PROCESS*"

$(OBJ_DIR_2)%.o:	$(SRC_DIR_2)%.c $(INCS)
									@$(CC) $(CFLAGS) -c $< -o $@
									echo "*MAGIC IN PROCESS AGAIN*"

$(OBJ_DIR_1):
									@mkdir -p $(OBJ_DIR_1)

$(OBJ_DIR_2):
									@mkdir -p $(OBJ_DIR_2)

clean :
									@rm -f $(OBJS_1)
									@rm -f $(OBJS_2)
									@rm -rf $(OBJ_DIR_1)
									@rm -rf $(OBJ_DIR_2)

fclean : 					clean
									@rm -f $(NAME_1)
									@rm -rf $(NAME_2)

re :			 				fclean all

norme :
									norminette $(SRC)
									norminette $(INC_DIR)
