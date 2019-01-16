#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 00:02:23 by bchanot           #+#    #+#              #
#    Updated: 2016/10/25 16:05:10 by bchanot          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEAD = includes/
SRCS = ft_atoi.c \
	ft_itoo.c \
	ft_striter.c \
	ft_strrchr.c \
	ft_bzero.c \
	ft_memalloc.c \
	ft_putnbr.c \
	ft_striteri.c \
	ft_strsplit.c \
	ft_isalnum.c \
	ft_isnum.c \
	ft_memccpy.c \
	ft_strjoin.c \
	ft_strstr.c \
	ft_isalpha.c \
	ft_memchr.c \
	ft_putstr.c \
	ft_strlcat.c \
	ft_strsub.c \
	ft_isascii.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strtrim.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_strcat.c \
	ft_strmap.c \
	ft_tolower.c \
	ft_isprint.c \
	ft_memdel.c \
	ft_strchr.c \
	ft_strmapi.c \
	ft_toupper.c \
	ft_itoa.c \
	ft_strclr.c \
	ft_strncat.c \
	ft_memmove.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_memset.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_putchar.c \
	ft_strdel.c \
	ft_strnequ.c \
	ft_strdup.c \
	ft_strnew.c \
	ft_putendl.c \
	ft_strequ.c \
	ft_strnstr.c \
	ft_cptchar.c \
	ft_puttab.c \
	ft_exit.c \
	ft_sqrt.c \
	ft_exit_err.c \
	ft_htoa.c \
	ft_utoa.c \
	ft_nbrlen.c \
	ft_unicode.c \
	ft_itob.c \
	ft_strnjoin.c \
	ft_getchar.c \
	ft_getstr.c \
	ft_strcut.c \
	ft_charjoin.c \
	ft_isupper.c \
	ft_check_last.c \
	ft_swap.c \
	ft_memdel2.c \
	ft_strisdigit.c \
	get_next_line.c \
	ft_printf.c \
	ft_printf/pf_b.c \
	ft_printf/pf_c.c \
	ft_printf/pf_c_up.c \
	ft_printf/pf_d_up.c \
	ft_printf/pf_di.c \
	ft_printf/pf_len.c \
	ft_printf/pf_more_inf.c \
	ft_printf/pf_o.c \
	ft_printf/pf_o_up.c \
	ft_printf/pf_p.c \
	ft_printf/pf_percent.c \
	ft_printf/pf_putnbr.c \
	ft_printf/pf_putnbrlong.c \
	ft_printf/pf_putstr.c \
	ft_printf/pf_s.c \
	ft_printf/pf_s_up.c \
	ft_printf/pf_take_inf.c \
	ft_printf/pf_u.c \
	ft_printf/pf_u_up.c \
	ft_printf/pf_x.c \
	ft_printf/pf_x_up.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\t---LIBFT---COMPILATED---"

.c.o:
	@clang $(FLAGS) -I$(HEAD) -c $< -o $(<:.c=.o)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
