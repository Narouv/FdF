# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 14:34:21 by rnauke            #+#    #+#              #
#    Updated: 2023/03/19 21:15:03 by rnauke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BONUS_NAME = $(NAME)

FLAGS = -Wall -Werror -Wextra

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)

SOURCES_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

PRINTF_DIR = ft_printf/
PRINTF_SOURCES = ft_printf_address.c ft_printf_char.c ft_printf_decimal.c ft_printf_hex.c ft_printf_itoa.c ft_printf_itoah.c ft_printf_main.c ft_printf_percent.c ft_printf_string.c ft_printf_ulltoah.c ft_printf_unsigned.c
PRINTF_OBJECTS = $(PRINTF_SOURCES:.c=.o)

PRINTF_OBJECT_DIR = $(addprefix $(PRINTF_DIR), $(PRINTF_OBJECTS))
PRINTF_SOURCES_DIR = $(addprefix $(PRINTF_DIR), $(PRINTF_SOURCES))

all: ${NAME}

bonus: $(NAME) $(OBJECTS_BONUS)

${NAME}: $(PRINTF_OBJECT_DIR)
	gcc -c $(SOURCES) $(FLAGS)
	ar -vcrs ${NAME} $(OBJECTS) $(PRINTF_OBJECT_DIR)

$(OBJECTS_BONUS):
	gcc -c $(SOURCES_BONUS) $(FLAGS)
	ar -vcrs ${NAME} $(OBJECTS_BONUS)

$(PRINTF_DIR)/%.o:
	gcc -c $(addprefix $(PRINTF_DIR), $(PRINTF_SOURCES)) $(FLAGS)

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)
	rm -f $(PRINTF_OBJECT_DIR)

fclean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)
	rm -f $(PRINTF_OBJECT_DIR)
	rm -f $(NAME)

.PHONY: re fclean clean

re: fclean all
