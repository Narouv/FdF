# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 18:26:14 by rnauke            #+#    #+#              #
#    Updated: 2022/09/09 17:05:06 by rnauke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
libNAME = ${NAME}.a
oNAME = ${NAME}.o

SOURCES = ft_printf_address.c ft_printf_char.c ft_printf_decimal.c ft_printf_hex.c ft_printf_itoa.c \
ft_printf_main.c ft_printf_percent.c ft_printf_string.c ft_printf_unsigned.c ft_itoa.c ft_putchar_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_toupper.c ft_printf_itoah.c \
ft_printf_ulltoah.c

all: ${libNAME}

${libNAME}: ${oNAME}
	ar -vcrs ${libNAME} *.o

${oNAME}:
	gcc -c $(SOURCES) -Wall -Werror -Wextra

clean:
	rm -f *.o

fclean:
	rm -f *.o ${libNAME}

re: fclean ${oNAME}
	ar -crsv ${libNAME} *.o
	rm *.o

.PHONY: all re fclean clean
