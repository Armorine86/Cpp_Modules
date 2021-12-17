NAME		=	diamondtrap
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -std=c++98 -fstandalone-debug -Wshadow
CC			=	clang++
RM			=	rm -rf

OBJ			=	obj

INCS		=	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
SRCS		=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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

.PHONY:		all clean fclean re format
