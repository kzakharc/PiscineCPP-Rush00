# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:33:22 by dkosolap          #+#    #+#              #
#    Updated: 2017/11/05 19:48:26 by dkosolap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

FLAG = -Wall -Wextra -Werror

NCURSES = -lncurses

SRC = main.cpp GameClass.cpp Object.cpp PlayerClass.cpp\
	  EnemiesClass.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAG) $(NCURSES)  $(OBJ) -o $(NAME)
%.o : %.cpp
	clang++ $(FLAG) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
