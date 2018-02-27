# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 17:52:34 by msteffen          #+#    #+#              #
#    Updated: 2018/02/27 18:41:18 by msteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC 					=	gcc
LD 					=	gcc

SRC_DIR				=	srcs
INCLUDE_DIR			=	includes

LDFLAGS				=	-g -Wall -Wextra -Werror -L libft -lft
CFLAGS				=	-g -c -Wall -Wextra -Werror -I libft/includes -I $(INCLUDE_DIR)

SRC 				=	ft_list.c ft_entry.c ft_ls_params.c main.c

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
libft: libft/libft.a
libft/libft.a:
	make -C libft
.PHONY: all clean fclean re libft
