NAME		=	template

CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -Wconversion\
				-Wshadow -std=c++98 -fstandalone-debug
				
CC			=	clang++

RM			=	rm -rf

OBJ			=	obj

INCS		=	whatever.hpp

SRCS		=	main.cpp

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
