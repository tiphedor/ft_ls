# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 17:52:34 by msteffen          #+#    #+#              #
#    Updated: 2018/03/07 13:57:45 by msteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 					=	clang
LD 					=	clang

SRC_DIR				=	srcs
INCLUDE_DIR			=	includes

LDFLAGS				=	-fsanitize=address -g -Wall -Wextra -Werror -Lft_printf -lftprintf
CFLAGS				=	-fsanitize=address -g -c -Wall -Wextra -Werror -I ft_printf/libft/includes -I ft_printf/includes -I $(INCLUDE_DIR)

SRC 				=	ft_sort.c ft_ls_print_l.c ft_entry.c ft_ls_params.c main.c

SRCS				=	$(addprefix $(SRC_DIR)/,$(SRC))
OBJS				=	$(patsubst %.c,%.o,$(SRCS))

NAME				=	ft_ls

all: libft $(NAME)

$(NAME): $(OBJS)
	$(LD) -o $(NAME) $(OBJS) $(FT_OBJS) $(LDFLAGS)
%.o: %.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
libft: ft_printf/libftprintf.a
ft_printf/libftprintf.a:
	make -C ft_printf
.PHONY: all clean fclean re libft
