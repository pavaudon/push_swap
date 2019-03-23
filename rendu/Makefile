# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 14:25:18 by pavaudon          #+#    #+#              #
#    Updated: 2019/03/23 19:40:03 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re norme libft

NAME_1		=	checker

NAME_2		= push_swap

SRC_DIR_1	=	./src/
SRC_1		=	ch_checker.c \
				ft_check_data.c \
				ft_stack_fill.c \
				ft_is_again.c \
				ch_application.c \
				ft_s_p_command.c \
				ft_r_rr_command.c

SRCS_1		=	$(addprefix $(SRC_DIR_1),$(SRC_1))

SRC_DIR_2	=	./src/
SRC_2		=	ps_push_swap.c \
				ft_check_data.c \
				ft_stack_fill.c \
				ft_is_again.c \
				ps_application.c \
				ft_s_p_command.c \
				ft_r_rr_command.c \
				ps_pos.c \
				ps_three.c \
				ps_four_five.c \
				ps_four_five_pr.c \
				ps_only_swap.c \
				ps_circle_sort.c \
				ps_big_list_sort.c \
				ps_good_place.c \
				ps_push_opti.c \
				ps_opti_command.c

SRCS_2		=	$(addprefix $(SRC_DIR_2),$(SRC_2))

OBJ_DIR_1	=	./obj_checker/
OBJS_1		=	$(addprefix $(OBJ_DIR_1),$(OBJ_1))
OBJ_1		=	$(SRC_1:.c=.o)

OBJ_DIR_2	=	./obj_push_swap/
OBJS_2		=	$(addprefix $(OBJ_DIR_2),$(OBJ_2))
OBJ_2		=	$(SRC_2:.c=.o)

INC			=	./includes/
INCLIB		=	./libft/includes/
INCS		=	$(INC) $(INCLIB)

CC			=	gcc

CFLAGS		=	-Wextra -Werror -Wall -I$(INC) -I$(INCLIB)
LDFLAGS		=	-L./libft -lft

all:			libft $(NAME_1) $(NAME_2)

libft:
				@make -C libft/

$(NAME_1):		$(OBJ_DIR_1) $(OBJS_1)
				@$(CC) $(CFLAGS) $(OBJS_1) -o $(NAME_1) -L./libft -lft
				@echo "checker is made"

$(NAME_2):		$(OBJS_2)
				@$(CC) $(OBJS_2) -o $(NAME_2) $(LDFLAGS) -g3
				@echo "push_swap is made"

$(OBJ_DIR_1)%.o:	$(SRC_DIR_1)%.c $(INCS)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_2)%.o:	$(SRC_DIR_2)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_1):
				@mkdir -p $(OBJ_DIR_1)

clean:
				@rm -rf $(OBJS_1)
				@rm -rf $(OBJ_DIR_1)
				@rm -rf $(OBJ_DIR_2)
				@make clean -C libft


fclean:			clean
				@rm -rf libft/libft.a
				@rm -rf $(NAME_1)
				@rm -rf $(NAME_2)

re:			fclean all
