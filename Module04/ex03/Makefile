# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 18:30:52 by mmondell          #+#    #+#              #
#    Updated: 2021/12/20 20:25:05 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	animals
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -Wconversion -Wshadow -std=c++98 -fstandalone-debug
CC			=	clang++
RM			=	rm -rf

OBJ			=	obj

INCS		=	Materia.hpp MateriaSource.hpp Character.hpp
SRCS		=	main.cpp Materia.cpp MateriaSource.cpp Character.cpp
OBJS		=	$(addprefix $(OBJ)/, $(SRCS:.cpp=.o))


$(OBJ)/%.o:	%.cpp
			$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(OBJS) -o $(NAME)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(NAME)

debug:		CFLAGS += -g
debug:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(OBJ) $(NAME)

re:			fclean all

format:
			@clang-format -i $(SRCS) $(INCS)

.PHONY:		all clean fclean re format
