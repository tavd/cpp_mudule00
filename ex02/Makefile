NAME = account

CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98 #-fsanitize=address -g

SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
