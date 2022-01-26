NAME		=	phonebook
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -std=c++98
CC			=	clang++
RM			=	rm -rf

OBJ			=	obj

INCS		=	Phonebook.hpp Contact.hpp
SRCS		=	main.cpp Contact.cpp Phonebook.cpp
OBJS		=	$(addprefix $(OBJ)/, $(SRCS:.cpp=.o))

$(OBJ)/%.o:	%.cpp
			$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(OBJS) -o $(NAME)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(NAME)

debug:		CFLAGS += -g
debug:		all

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(OBJ) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re format
