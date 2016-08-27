# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 16:35:37 by tgauvrit          #+#    #+#              #
#    Updated: 2016/08/27 10:41:39 by tanguy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =			libft_malloc_$(HOSTTYPE).so

LINK =			libft_malloc.so

CC =			clang

FLAGS =			-Wall -Werror -Wextra -fPIC

HEADERS =		-I ./include -I $(LIBFT_DIR)

LIBRARIES =		-L$(LIBFT_DIR) -l$(LIBFT_NAME)

LIBFT_NAME =	ft

LIBFT =			$(LIBFT_DIR)lib$(LIBFT_NAME).a

LIBFT_DIR =		./libft/

SRC_DIR =		./src/

OBJ_DIR_NAME =	obj
OBJ_DIR =		./obj/

FILENAMES =		free malloc realloc show_alloc_mem alloc_data

OBJ_PATHS :=	$(addsuffix .o,$(FILENAMES))
OBJ_PATHS :=	$(addprefix $(OBJ_DIR),$(OBJ_PATHS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_PATHS)
	$(CC) $(OBJ_PATHS) $(HEADERS) $(LIBRARIES) -shared -o $(NAME)
	@/bin/rm -f $(LINK)
	ln -s $(NAME) $(LINK)

$(OBJ_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

$(LIBFT):
	(cd $(LIBFT_DIR) && make)

clean:
	-/bin/rm -f $(OBJ_PATHS)
	/usr/bin/find . -name "$(OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	-/bin/rm -f $(NAME) $(LINK)

re: fclean all
