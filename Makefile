# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 17:24:04 by pavaudon          #+#    #+#              #
#    Updated: 2018/03/07 17:24:07 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

NAME_1 = 					checker

#NAME_2 = 					push_swap

CC = 						gcc
CFLAGS = 					-Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT)

SRC_DIR =					./src/
SRC_1 = 					ft_checker.c \
							ft_command.c \
							ft_valide.c

#SRC_2 =  					ft_push_swap.c \

SRCS_1 =					$(addprefix $(SRC_DIR),$(SRC_1))

#SRCS_2 = 					$(addprefix $(SRC_DIR,$(SRC_2)))

OBJ_DIR_1 =					./obj_ch/
OBJ_1 = 					$(SRC_1:.c=.o)
OBJS_1 =					$(addprefix $(OBJ_DIR_1),$(OBJ_1))

#OBJ_DIR_2 =				./obj_ps/
#OBJ_2 = 					$(SRC_2:.c=.o)
#OBJS_2 =					$(addprefix $(OBJ_DIR_2),$(OBJ_2))

LIBFT =						libft/includes

INC_DIR =					./includes/
INC =						push_swap.h
INCS =						$(addprefix $(INC_DIR),$(INC))


# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m


all : 						$(NAME_1) #$(NAME_2)

$(NAME_1) :				$(OBJ_DIR_1) $(OBJS_1)
							@make re -C libft/
							@ar rc $(NAME_1) $(OBJS_1)
							@ranlib $(NAME_1)
							@echo "${_YELLOW}*$(NAME_1)* ${_WHITE}appeared"

#$(NAME_2) :				$(OBJ_DIR_2) $(OBJS_2)
#							@ar rc $(NAME_2) $(OBJS_2)
#							@ranlib $(NAME_2)
#							echo *$(NAME_2)* appeared

$(OBJ_DIR_1)%.o:	$(SRC_DIR)%.c $(INCS)
							@$(CC) $(CFLAGS) -c $< -o $@
							@echo "${_YELLOW}*CHECKER IN PROCESS*${_WHITE}"

#$(OBJ_DIR_2)%.o:	$(SRC_DIR)%.c $(INCS)
#							@$(CC) $(CFLAGS) -c $< -o $@
#							@echo "*PUSH_SWAP IN PROCESS AGAIN*"

$(OBJ_DIR_1):
							@mkdir -p $(OBJ_DIR_1)

#$(OBJ_DIR_2):
#							@mkdir -p $(OBJ_DIR_2)

clean :
							@rm -f $(OBJS_1)
#							@rm -f $(OBJS_2)
							@rm -rf $(OBJ_DIR_1)
#							@rm -rf $(OBJ_DIR_2)

fclean : 					clean
							@rm -f $(NAME_1)
#							@rm -rf $(NAME_2)
							@make fclean -C libft/

re :		 				fclean all

norme :
							norminette $(SRC_DIR)
							norminette $(INC_DIR)
