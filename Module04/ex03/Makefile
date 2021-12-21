# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 18:30:52 by mmondell          #+#    #+#              #
#    Updated: 2021/12/21 10:58:14 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	materia

CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -Wconversion\
				-Wshadow -std=c++98 -fstandalone-debug
				
CC			=	clang++

RM			=	rm -rf

OBJ			=	obj

INCS		=	AMateria.hpp IMateriaSource.hpp MateriaSource.hpp\
				Character.hpp ICharacter.hpp Cure.hpp Ice.hpp 

SRCS		=	main.cpp AMateria.cpp MateriaSource.cpp\
				Character.cpp Cure.cpp Ice.cpp 

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
