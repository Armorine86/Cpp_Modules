# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 18:30:52 by mmondell          #+#    #+#              #
#    Updated: 2022/01/28 09:01:59 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	animals
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -Wshadow -std=c++98 -fstandalone-debug
CC			=	clang++
RM			=	rm -rf

OBJ			=	obj

INCS		=	Animal.hpp Dog.hpp Cat.hpp Brain.hpp
SRCS		=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
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
