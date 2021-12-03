NAME =		megaphone
SRCS =		megaphone.cpp
OBJS =		megaphone.o

CC =		clang++ 
CFLAGS =	-Wall -Werror -Wextra -c -std=c++98


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\\n\033[32;1m MEGAPHONE HAS BEEN GENERATED \033[0m \\n"

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Created: $@"

debug: CFLAGS += -g
debug: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "\033[34;1m CLEANED OBJECT FILES \033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[34;1m CLEANED MEGAPHONE \033[0m"

re: fclean all

.PHONY: all clean fclean re
