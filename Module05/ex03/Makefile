
NAME		=	bureaucrat

CFLAGS		=	-Wall -Werror -Wextra -Wpedantic\
				-Wshadow -std=c++98 -fstandalone-debug
				
CC			=	clang++

RM			=	rm -rf

OBJ			=	obj

INCS		=	Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp\
				RobotomyRequestForm.hpp PresidentialPardonForm.hpp\
				Intern.hpp

SRCS		=	main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp\
				RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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
			@$(RM) $(OBJ) $(NAME) *_shrubbery

re:			fclean all

format:
			@clang-format -i $(SRCS) $(INCS)

.PHONY:		all clean fclean re format
