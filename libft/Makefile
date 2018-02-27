# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 15:28:13 by msteffen          #+#    #+#              #
#    Updated: 2018/02/27 17:59:25 by msteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

CC				=	gcc
LD				=	ar

CFLAGS			=	-Wall -Werror -Wextra -c -I includes
LDFLAGS			=	rcs

SOURCESS		=	ft_strreplace.c ft_gnl.c ft_putnstr_fd.c ft_putnstr.c ft_putnchar_fd.c ft_putnchar.c ft_putnbr_base.c ft_putnbr_base_fd.c ft_isoneof.c ft_int_min.c ft_int_max.c ft_int_sort.c ft_int_average.c ft_strtolower.c ft_strtoupper.c ft_strnjoin.c ft_intlen.c ft_sqrt.c ft_strndup.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_strchr.c ft_strrchr.c ft_strsplit.c ft_strnstr.c ft_strstr.c ft_memmove.c ft_strlcat.c ft_strncpy.c ft_strncat.c ft_strcat.c ft_strcpy.c ft_strtrim.c ft_strsub.c ft_abs.c ft_itoa.c ft_strjoin.c ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_striteri.c ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c ft_memalloc.c ft_putnbr.c ft_putendl.c ft_putstr.c ft_putchar.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_memchr.c ft_memccpy.c ft_memcmp.c ft_memcpy.c ft_strdup.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_memset.c ft_strcmp.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c
SOURCES			=	$(addprefix src/,$(SOURCESS))

OBJS			:= 	$(patsubst %.c,%.o,$(SOURCES))

all: $(NAME)
$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
install: all
	/bin/cp -rf includes/libft.h /usr/local/include
	/bin/cp -rf libft.a /usr/local/lib
.PHONY: all clean fclean re install
