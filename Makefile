# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 17:59:41 by rnauke            #+#    #+#              #
#    Updated: 2023/03/22 17:10:45 by rnauke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_PATH = ./MLX42/Build/libmlx42.a

OBJECTS_DIR = obj
SOURCES_DIR = src

SOURCES = 
OBJECTS = $(SOURCES:.c=.o)

DIR_SRC = $(addprefix $(SOURCES_DIR)/, $(SOURCES))
DIR_OBJ = $(addprefix $(OBJECTS_DIR)/, $(OBJECTS))

FLAGS = -Wall -Werror -Wextra
INCLUDES = -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit -lm
ARGS = $(LIBFT) $(INCLUDES) $(FLAGS)

# bonus
# BONUS_NAME = $(NAME)_bonus

# BONUS_DIR = bonus
# OBJECTS_BONUS_DIR = $(addprefix $(BONUS_DIR)/, $(OBJECTS_DIR))
# SOURCES_BONUS_DIR = $(addprefix $(BONUS_DIR)/, $(SOURCES_DIR))

# SOURCES_BONUS = 
# OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

# DIR_SRC_BNS = $(addprefix $(BONUS_DIR)/, $(addprefix $(SOURCES_DIR)/, $(SOURCES_BONUS)))
# DIR_OBJ_BNS = $(addprefix $(BONUS_DIR)/, $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_BONUS)))

all:  $(LIBFT) $(EXEC)

# bonus: $(BONUS_NAME)

# $(BONUS_NAME): $(DIR_OBJ_BNS)
# 	ar -vcrs $(BONUS_NAME) $(DIR_OBJ_BNS)
	
# $(OBJECTS_BONUS_DIR)/%.o : $(SOURCES_BONUS_DIR)/%.c
# 	mkdir -p $(BONUS_DIR)/$(OBJECTS_DIR)
# 	gcc -o $@ -c $< $(ARGS) $(FLAGS)

$(NAME): $(DIR_OBJ)
	gcc -o fdf src/client.c $(ARGS)

# $(LIB_NAME) : $(DIR_OBJ)
# 	ar -vcrs $(LIB_NAME) $(DIR_OBJ)

$(OBJECTS_DIR)/%.o : $(SOURCES_DIR)/%.c
	mkdir -p $(OBJECTS_DIR)
	gcc -o $@ -c $< $(ARGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	rm -rf $(OBJECTS_DIR)
	rm -rf $(BONUS_DIR)/$(OBJECTS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	rm -rf $(OBJECTS_DIR)
	rm -rf $(BONUS_DIR)/$(OBJECTS_DIR)
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: re fclean clean

re: fclean all
