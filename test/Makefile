# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 16:35:37 by tgauvrit          #+#    #+#              #
#    Updated: 2016/08/27 10:41:22 by tanguy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			test_malloc

CC =			clang

FLAGS =			-Wall -Werror -Wextra

FT_MALLOC =		../libft_malloc.so

LIBRARIES =		-L.. -lft_malloc

HEADERS =		-I ../include -I ../libft

SRC_DIR =		./src/

OBJ_DIR_NAME =	obj
OBJ_DIR =		./obj/

FILENAMES =		main

OBJ_PATHS :=	$(addsuffix .o,$(FILENAMES))
OBJ_PATHS :=	$(addprefix $(OBJ_DIR),$(OBJ_PATHS))

all: $(NAME)

$(NAME): $(FT_MALLOC) $(OBJ_PATHS)
	$(CC) $(FLAGS) $(HEADERS) $(LIBRARIES) $(OBJ_PATHS) -o $(NAME)

$(FT_MALLOC):
	(cd .. && make re)

$(OBJ_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

clean:
	-/bin/rm -f $(OBJ_PATHS)
	/usr/bin/find . -name "$(OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all
	(cd .. && make re)
