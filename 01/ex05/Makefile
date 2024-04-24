CXX = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Harl2_0
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
