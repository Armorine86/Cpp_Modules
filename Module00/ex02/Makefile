NAME		=	tests
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -std=c++98
CC			=	clang++
RM			=	rm -rf

OBJ			=	obj

INCS		=	Account.hpp
SRCS		=	tests.cpp Account.cpp
OBJS		=	$(addprefix $(OBJ)/, $(SRCS:.cpp=.o))

$(OBJ)/%.o:	%.cpp
			$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(OBJS) -o $(NAME)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(OBJ) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re format
