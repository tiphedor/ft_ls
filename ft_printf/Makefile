# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:52:30 by msteffen          #+#    #+#              #
#    Updated: 2018/03/07 13:49:10 by msteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	 		= gcc
LD   		= ar

CFLAGS 		= -c -Wall -Wextra -Werror
LDFLAGS		= rcs
INCLUDES 	= -I includes -I libft/includes

NAME 		= libftprintf.a
SRCS 		= src/ft_buffer.c src/ft_buffer_operations.c src/ft_casts.c src/ft_conversions.c src/ft_conversions_b.c src/ft_conversions_cs.c src/ft_conversions_cs_pad.c src/ft_conversions_cx_tools.c src/ft_conversions_diu.c src/ft_conversions_ox.c src/ft_conversions_p.c src/ft_conversions_x_tools.c src/ft_flags.c src/ft_printf.c src/ft_styling.c src/ft_unicode_conversions.c src/ft_unicode_print.c src/ft_unicode_tools.c src/nb_utils.c libft/src/ft_abs.c libft/src/ft_atoi.c libft/src/ft_bzero.c libft/src/ft_gnl.c libft/src/ft_lstsort.c libft/src/ft_lstrev.c libft/src/ft_int_average.c libft/src/ft_int_max.c libft/src/ft_int_min.c libft/src/ft_int_sort.c libft/src/ft_intlen.c libft/src/ft_isalnum.c libft/src/ft_isalpha.c libft/src/ft_isascii.c libft/src/ft_isdigit.c libft/src/ft_islower.c libft/src/ft_isoneof.c libft/src/ft_isprint.c libft/src/ft_isspace.c libft/src/ft_isupper.c libft/src/ft_itoa.c libft/src/ft_lstadd.c libft/src/ft_lstdel.c libft/src/ft_lstdelone.c libft/src/ft_lstiter.c libft/src/ft_lstmap.c libft/src/ft_lstnew.c libft/src/ft_memalloc.c libft/src/ft_memccpy.c libft/src/ft_memchr.c libft/src/ft_memcmp.c libft/src/ft_memcpy.c libft/src/ft_memdel.c libft/src/ft_memmove.c libft/src/ft_memset.c libft/src/ft_putchar.c libft/src/ft_putchar_fd.c libft/src/ft_putendl.c libft/src/ft_putendl_fd.c libft/src/ft_putnbr.c libft/src/ft_putnbr_base.c libft/src/ft_putnbr_base_fd.c libft/src/ft_putnbr_fd.c libft/src/ft_putnchar.c libft/src/ft_putnchar_fd.c libft/src/ft_putnstr.c libft/src/ft_putnstr_fd.c libft/src/ft_putstr.c libft/src/ft_putstr_fd.c libft/src/ft_sqrt.c libft/src/ft_strcat.c libft/src/ft_strchr.c libft/src/ft_strclr.c libft/src/ft_strcmp.c libft/src/ft_strcpy.c libft/src/ft_strdel.c libft/src/ft_strdup.c libft/src/ft_strequ.c libft/src/ft_striter.c libft/src/ft_striteri.c libft/src/ft_strjoin.c libft/src/ft_strlcat.c libft/src/ft_strlen.c libft/src/ft_strmap.c libft/src/ft_strmapi.c libft/src/ft_strncat.c libft/src/ft_strncmp.c libft/src/ft_strncpy.c libft/src/ft_strndup.c libft/src/ft_strnequ.c libft/src/ft_strnew.c libft/src/ft_strnjoin.c libft/src/ft_strnstr.c libft/src/ft_strrchr.c libft/src/ft_strreplace.c libft/src/ft_strsplit.c libft/src/ft_strstr.c libft/src/ft_strsub.c libft/src/ft_strtolower.c libft/src/ft_strtoupper.c libft/src/ft_strtrim.c libft/src/ft_tolower.c libft/src/ft_toupper.c
OBJS 		= $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)
$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(NAME) $(OBJS)
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re:
	@make fclean --no-print-directory
	@make all --no-print-directory

.PHONY: re fclean clean all
