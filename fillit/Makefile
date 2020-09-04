# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiego <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 15:20:36 by sdiego            #+#    #+#              #
#    Updated: 2019/10/04 11:32:23 by sdiego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./src/main.c ./src/minilibft.c ./src/read.c ./src/solve.c ./src/tetri.c \
	  ./src/mem_lst.c

OBJ = $(SRC:.c=.o)

INCLUDES = ./includes

HEADERS = $(INCLUDES)/fillit.h $(INCLUDES)/mem_lst.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I$(INCLUDES)

.c.o:
	gcc -Wall -Wextra -Werror -I./$(INCLUDES) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
