NAME = account

CC = c++
FLAGS = -Werror -Wextra -Wall

SRC = tests.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAG) $(SRC) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :
	@rm -f $(NAME)
re : fclean all