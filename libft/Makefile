# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoroita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 12:24:33 by anoroita          #+#    #+#              #
#    Updated: 2018/07/09 07:05:50 by anoroita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCSDIR = includes/

SRCSDIR = srcs/

OBJSDIR = objs/

SRCS = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_abs.c \
		ft_words.c \
		ft_nbrlen_one.c \
		ft_swap.c \
		ft_strndup.c \
		ft_strrev.c \
		ft_memmove.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isupper.c \
		ft_islower.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_remove_char.c \
		ft_remove_str.c \
		ft_char_index.c \
		ft_str_index.c \
		ft_int_index.c \
		ft_strstr_index.c \
		ft_printf.c \
		ft_putwchar.c \
		ft_putwchar_fd.c \
		ft_putwstr.c \
		ft_putwstr_fd.c \
		ft_error.c \
		get_next_line.c \
		ft_manage_b.c \
		ft_manage_buffer.c \
		ft_manage_c.c \
		ft_manage_d.c \
		ft_manage_flag.c \
		ft_manage_o.c \
		ft_manage_p.c \
		ft_manage_s.c \
		ft_manage_star.c \
		ft_manage_u.c \
		ft_manage_n.c \
		ft_manage_undefined.c \
		ft_manage_us.c \
		ft_manage_x.c \
		ft_check_next.c \
		ft_check.c \
		ft_pointers.c \
		ft_paint.c \
		ft_size.c \
		ft_print.c \
		ft_universal.c

		

OBJS = $(addprefix $(OBJSDIR),$(SRCS:.c=.o))

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -I $(INCSDIR) -o $@ -c $<

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
